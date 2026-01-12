#include"header.h"
void my_isr(int n)
{
	printf("IN ISR   signalnumber=%d  pid=%d\n",n,getpid());
	wait(0);
}
void main()
{
	if(fork()==0)
	{
		printf("In Child pid=%d\n",getpid());
		sleep(20);
		printf("After the 20 sec \n");
	}
	else
	{
		printf("IN Perent pid=%d\n",getpid());
		signal(14,my_isr);
		while(1);
	}

}
