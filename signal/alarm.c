// alarm is to use set alarm clock to send signal 
#include"header.h"
void my_isr(int n)
{
	printf("IN ISR  signalnumber=%d  pid=%d \n",n,getpid());
}
void main()
{
	printf("Hello   pid=%d\n",getpid());
	signal(14,my_isr);
	alarm(10);  // after 10 sec process goes into isr and come back to main
	printf("Hai....\n");
	while(1);
}
