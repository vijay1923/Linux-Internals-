#include"header.h"
static int a=10;
int main()
{
	int b=20;
	int ret,r;
	printf("Hai..\n");
	ret=fork();
	if(ret==0)
	{
		printf("In child \n pid=%d  ppid=%d \n",getpid(),getppid());
		printf("a=%d  b=%d  \n",a,b);
		a=2*a;
		b=2*b;
		printf("a=%d  b=%d\n",a,b);
	}
	else
	{
		printf("In perent \n pid=%d  ppid=%d\n",getpid(),getppid());
		printf("a=%d  b=%d\n",a,b);
		a=3*a;
		b=3*b;
		printf("a=%d  b=%d\n",a,b);
	}
	sleep(1);
}
