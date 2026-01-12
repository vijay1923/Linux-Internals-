#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "header.h"

// Global counters
long long total_accesses = 0;
long long page_faults_replaced = 0;
long long dirty_pages_written = 0;

// Extra stats
long long total_hits = 0;
long long total_faults = 0;

// Global configuration
int debug_mode = 0;

int main(int argc, char *argv[])
{
    if (argc != 6) {
        printf("Usage: %s <VMbits> <PageBits> <NumFrames> <tracefile> <d/n>\n", argv[0]);
        return 1;
    }

    int VM_bits = atoi(argv[1]);
    int Page_bits = atoi(argv[2]);
    int NumFrames = atoi(argv[3]);
    char *tracefile = argv[4];
    debug_mode = (argv[5][0] == 'd') ? 1 : 0;

    long long VirtualMemory = 1LL << VM_bits;
    long long PageSize      = 1LL << Page_bits;
    long long TotalPages    = VirtualMemory / PageSize;

    size_t page_table_bytes = (size_t)TotalPages * sizeof(long);

    printf("Memory Management Simulator Initialized\n");
    printf("Virtual Memory Size: %lld bytes\n", VirtualMemory);
    printf("Page Size          : %lld bytes\n", PageSize);
    printf("Total Virtual Pages: %lld\n", TotalPages);
    printf("Physical Frames    : %d\n", NumFrames);
    printf("Trace File         : %s\n", tracefile);
    printf("Debug Mode         : %s\n", debug_mode ? "ON" : "OFF");

    long *page_table = malloc(sizeof(long) * TotalPages);
    if (!page_table) {
        fprintf(stderr, "Failed to allocate %lld entries (%lu bytes)\n",
                TotalPages, (unsigned long)page_table_bytes);
        return 1;
    }

    for (long long i = 0; i < TotalPages; ++i)
        page_table[i] = -1;

    Frame *frames = malloc(sizeof(Frame) * NumFrames);
    if (!frames) {
        perror("malloc frames");
        free(page_table);
        return 1;
    }

    for (int i = 0; i < NumFrames; ++i) {
        frames[i].vpage = -1;
        frames[i].ref_count = 0;
        frames[i].dirty = 0;
        frames[i].timestamp = 0;
        frames[i].just_loaded = 0;
    }

    FILE *fp = fopen(tracefile, "r");
    if (!fp) {
        perror("fopen");
        free(page_table);
        free(frames);
        return 1;
    }

    long long address;
    char mode;
    int decay_counter = 0;

    while (fscanf(fp, "%lld %c", &address, &mode) == 2)
    {
        total_accesses++;
        long long vpage = address >> Page_bits;

        if (debug_mode)
            printf("Access %lld: addr=%lld page=%lld mode=%c\n",
                   total_accesses, address, vpage, mode);

        long frame_index = page_table[vpage];

        // -------------------------------
        // PAGE HIT
        // -------------------------------
        if (frame_index != -1) {
            total_hits++;
            Frame *f = &frames[frame_index];

            if (f->just_loaded)
                f->just_loaded = 0;
            else if (f->ref_count < 10)
                f->ref_count++;

            if (mode == 'w' || mode == 'W')
                f->dirty = 1;

            if (debug_mode)
                printf("Page %lld hit in frame %ld, ref=%d dirty=%d\n",
                       vpage, frame_index, f->ref_count, f->dirty);
        }

        // -------------------------------
        // PAGE FAULT
        // -------------------------------
        else {
            total_faults++;

            int free_frame = -1;
            for (int i = 0; i < NumFrames; i++)
                if (frames[i].vpage == -1) {
                    free_frame = i;
                    break;
                }

            // LOAD INTO FREE FRAME
            if (free_frame != -1) {
                frames[free_frame].vpage = vpage;
                frames[free_frame].ref_count = 3;
                frames[free_frame].dirty = (mode == 'w');
                frames[free_frame].timestamp = total_accesses;
                frames[free_frame].just_loaded = 1;

                page_table[vpage] = free_frame;

                if (debug_mode)
                    printf("Page NULL replaced by Page %lld in frame %d\n", vpage, free_frame);
            }

            // REPLACEMENT NEEDED
            else {
                int victim = -1;
                long long oldest_ts = LLONG_MAX;

                while (victim == -1) {
                    for (int i = 0; i < NumFrames; i++) {
                        if (frames[i].ref_count == 0 &&
                            frames[i].timestamp < oldest_ts) {
                            oldest_ts = frames[i].timestamp;
                            victim = i;
                        }
                    }

                    if (victim == -1) {
                        for (int i = 0; i < NumFrames; i++)
                            if (frames[i].ref_count > 0)
                                frames[i].ref_count--;
                    }
                }

                Frame *vf = &frames[victim];

                if (debug_mode)
                    printf("Page %d replaced by Page %lld\n",
                           vf->vpage, vpage);

                if (vf->dirty) {
                    dirty_pages_written++;
                    if (debug_mode)
                        printf("Page %d was dirty\n", vf->vpage);
                }

                page_table[vf->vpage] = -1;

                vf->vpage = vpage;
                vf->ref_count = 3;
                vf->dirty = (mode == 'w');
                vf->timestamp = total_accesses;
                vf->just_loaded = 1;

                page_table[vpage] = victim;
                page_faults_replaced++;
            }
        }

        // GLOBAL DECAY EVERY 4 ACCESSES
        decay_counter++;
        if (decay_counter == 4) {
            decay_counter = 0;
            for (int i = 0; i < NumFrames; i++)
                if (frames[i].ref_count > 0)
                    frames[i].ref_count--;
        }
    }

    fclose(fp);

    // -------------------------------
    // PRINT SUMMARY
    // -------------------------------
    printf("\n===== SIMULATION SUMMARY =====\n");
    printf("Total Memory Accesses               : %lld\n", total_accesses);
    printf("Total Page Faults (including loads) : %lld\n", total_faults);
    printf("Page Faults (that replaced a page)  : %lld\n", page_faults_replaced);
    printf("Pages Written to Disk               : %lld\n", dirty_pages_written);
    printf("Total Page Hits                     : %lld\n", total_hits);

    // FRAME TABLE
    printf("\nFinal Frame Table:\n");
    for (int i = 0; i < NumFrames; i++) {
        if (frames[i].vpage == -1)
            printf("Frame %2d : <empty>\n", i);
        else
            printf("Frame %2d : %6ld %9d %5d %12ld\n",
                   i,
                   (long)frames[i].vpage,
                   frames[i].ref_count,
                   frames[i].dirty,
                   frames[i].timestamp);
    }

    free(page_table);
    free(frames);
    return 0;
}
