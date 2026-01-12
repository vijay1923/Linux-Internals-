// set alarm of user wish and decrement alarm by 1 untill 0 and after that kill that process
#include"header.h"
int i;  // global variable to access in entire program
void my_isr(int n)
{
	i--;	
	printf("IN ISR signalnumber=%d pid=%d\n",n,getpid());
	if(i==0)  // if i becomes 0 then kill the  process
	raise(9);  // kill the same process
	else
	alarm(i);  // set decremented alarm 
}
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./a.out signum\n");
		return;
	}
	printf("Hello  pid=%d\n",getpid());
	signal(14,my_isr);   // set new action to the alarm signal
	i=atoi(argv[1]);
	printf("i=%d\n",i);  // print user provided value 
	alarm(i);  // set alarm of user provided value 
	printf("Hai...\n");
	while(1);
}
