// sigaction fun in child and perent procesess 
#include"header.h"
void my_isr(int n)
{
	printf("IN ISR  n=%d  pid=%d\n",n,getpid());
}
void main()
{
	if(fork()==0)
	{
		printf("IN CHILD   pid=%d\n",getpid());
		while(1);
	}
	else
	{
		printf("IN PERENT  pid=%d\n",getpid());
		struct sigaction v;
		v.sa_handler=my_isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags=0;
		sigaction(SIGINT,&v,0);
		while(1);
	}
}
