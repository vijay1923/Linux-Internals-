// if CNTL+C signal comes it need to execute my_isr 3 times after default job of CNTL+C 
// if CNTL+ \ signal comes it need to executr my_isr 2 times after default job of CNTL + \ need to done 
#include"header.h"
void my_isr(int n)
{
	static int c1=0, c2=0;
	printf("IN ISR signal number =%d pid=%d\n",n,getpid());
	if(n==3)
	c1++;
	else if(n==2)
	c2++;
	if(c1==3)
	signal(SIGINT,SIG_DFL);
	if(c2==2)
	signal(SIGQUIT,SIG_DFL);
}
void main()
{
	printf("Hello    pid=%d\n",getpid());
	signal(SIGINT,my_isr);
	signal(SIGQUIT,my_isr);
	printf("Hai....\n");
	while(1);
}
