#include<stdio.h>
void my_getpid(void )
{
	static int fg=4;
	if(--fg)
	{
		my_getpid();
		printf("%d ",fg);
	}

}
int main()
{
	my_getpid();
	printf("perror\n");

}
