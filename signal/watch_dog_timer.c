#include"header.h"
int chlpid;
void my_isr(int n)
{
	printf("IN ISR   n=%d\n",n);
	if(n==SIGCHLD)
	{
		printf("Child completes \n");
	}
	else if(n==SIGALRM)
	{
		if(kill(chlpid,0)!=-1)  // check child process is still alive or not 
		{
			printf("Child terminated \n");
			signal(SIGCHLD,SIG_DFL); // IF TERMINATEED IGNORE SIGCHILD DIGNAL
			kill(chlpid,9);
		}
	}
}
void main()
{
	int d;
	if((chlpid==fork())==0)
	{
		srand(getpid()); // random delay generation
		d=rand()%10+1;
		printf("In Child..  %d \n",d);
		sleep(d);
		printf("Out child...\n");
		while(1);
	}
	else
	{
		struct sigaction v;
		v.sa_handler=my_isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags=SA_NOCLDSTOP|SA_NOCLDWAIT;
		sigaction(SIGCHLD,&v,0);
		v.sa_flags=0;
		sigaction(SIGALRM,&v,0);
		alarm(5);
		printf("Hello..\n");
		sleep(10);
		while(1);
	}
}
