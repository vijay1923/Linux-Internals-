#include<stdio.h>
int main()
{
	int _fork=55;
	char *_wait=& _fork;
	*++_wait=4;
	*--_wait=6;
	printf("%d \n",_fork);

}
