// sigaction function used as like signal function
#include"header.h"
void my_isr(int n)
{
	printf("IN ISR   n=%d  pid=%d \n",n,getpid());
}
int main()
{
	printf("HELLO   pid=%d\n",getpid());
	//signal(SIGINT,my_isr);  // set new action for signal cntl + c
	
	// sigaction function 
	// step 1->  create a variable 
	struct sigaction v;
	// step 2-> fill the necessary members 
	v.sa_handler=my_isr;
	sigemptyset(&v.sa_mask);
	v.sa_flags=0;
	/// call the fun
	sigaction(SIGINT,&v,0);

	printf("HAI...\n");
	while(1);

}

