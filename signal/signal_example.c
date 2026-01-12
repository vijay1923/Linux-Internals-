// when CNTL+C signal comes less than 3 times then it need to execute ISR or else execude default job of CNTL+C
#include"header.h"
void my_isr(int n)
{
	static int c=0;
	printf("In ISR signalnumber=%d  pid=%d\n",n,getpid());
	c++;
	if(c==3)
	signal(SIGINT,SIG_DFL);  // do default job 
}
void main()
{
	printf("Hello    pid=%d\n",getpid());
	signal(SIGINT,my_isr);	// here changing action of SIGINT to my_isr
	printf("Haii....\n");
	while(1);
}
