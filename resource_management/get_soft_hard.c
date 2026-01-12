#include"header.h"
int main()
{
	struct rlimit v;

	getrlimit(RLIMIT_STACK,&v);  // to get min and max stack for a processes
	printf("Stack :Soft limit:%u || Hard limit:%u\n",(int)v.rlim_cur,(int)v.rlim_max);

	getrlimit(RLIMIT_CPU,&v);  // min and max cpu time per process 
	printf("CPU time : Soft limit:%u || Hard limit:%u \n",(int)v.rlim_cur,(int)v.rlim_max);

	getrlimit(RLIMIT_FSIZE,&v);  // min and max  file size can create by process 
	printf("File size : Soft limit:%u || Hard limit:%u\n",(int)v.rlim_cur,(int)v.rlim_max);

	getrlimit(RLIMIT_NPROC,&v);  // min and max  number of procesess can be create 
	printf("Number of processes : Soft limit:%u || Hard limit:%u\n",(int)v.rlim_cur,(int)v.rlim_max);

	getrlimit(RLIMIT_NOFILE,&v);  // min and max files that can be creates by a process 
	printf("Number of files :Soft limit:%u || Hard limit:%u\n",(int)v.rlim_cur,(int)v.rlim_max);
}
