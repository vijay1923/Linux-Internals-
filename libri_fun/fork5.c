#include"header.h"
int main()
{
	int r;
	printf("Heloo  pid=%d\n",getpid());
	r=fork();
	if(r==0)
	{
		printf("In the child  pid=%d\n",getpid());
	}
	else
	{
		printf("In the perent  pid=%d\n",getpid());
	}
	while(1);
}
