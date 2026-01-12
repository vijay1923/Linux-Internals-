// 1st process will get 10 sec alarm after that every 2 sec process will get alarm
#include"header.h"
void my_isr(int n)
{
	printf("IN ISR signalnumber=%d pid=%d\n",n,getpid());
	alarm(2);  // set alarm of 2 sec
}
void main()
{
	printf("Hello     pid=%d\n",getpid());
	signal(14,my_isr);
	alarm(10); // set alarm of 10 sec
	printf("Hai....\n");
	while(1);
}
