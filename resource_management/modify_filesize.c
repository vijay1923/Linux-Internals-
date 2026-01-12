#include"header.h"
#include<string.h>
void my_isr(int n)
{
	printf("IN ISR signal no=%d || describe signal:%s\n",n,strsignal(n));
}
void main()
{
	FILE *p;
	struct rlimit v;
	signal(SIGXFSZ,my_isr);
	printf("Before Modyfing\n");
	getrlimit(RLIMIT_FSIZE,&v);  // to get min and max file size 
	printf("Filesize:- soft limit:%u || hard limit:%u\n",(int)v.rlim_cur,(int)v.rlim_max);
	v.rlim_cur=5;
	setrlimit(RLIMIT_FSIZE,&v);

	printf("After Modyfing\n");
	getrlimit(RLIMIT_FSIZE,&v);
	printf("Filesize:- soft limit:%u || harrd limit:%u\n",(int)v.rlim_cur,(int)v.rlim_max);

	p=fopen("D1","w");
	fwrite("abcdefgh",12,1,p);

}
