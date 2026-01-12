#ifndef HEADER_H
#define HEADER_H

typedef struct {
    int vpage;        // virtual page stored here (-1 if empty)
    int ref_count;    // reference count (0..10)
    int dirty;        // 1 if dirty (written), 0 otherwise
    long timestamp;   // FIFO ordering (lower = older)
    int just_loaded;  // 1 if the page was loaded but not yet accessed (first access doesn't inc)
} Frame;

#endif
