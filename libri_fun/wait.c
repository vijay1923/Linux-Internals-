#include"header.h"
int main()
{
	if(fork()==0)
	{
		printf("In child pid=%d\n",getpid());
		sleep(10);
		printf("In child after sleep..\n");
		exit(1);
	}
	else
	{
		int r,s;
		printf("In perent before wait  pid=%d\n",getpid());
		r=wait(&s);
		printf("In perent after the wait r=%d s=%d\n",r,s);
	}

}
