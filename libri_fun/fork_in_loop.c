#include"header.h"
int main()
{
	int i;
	printf("Hello...pid=%d\n",getpid());
	for(i=0;i<3;i++)
	{
		if(fork()==0)
		printf("Hai...pid=%d\n",getpid());
		else
		printf("Bye... pid=%d\n",getpid());
	}
	while(1);
}
