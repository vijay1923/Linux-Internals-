#include"header.h"
int main()
{
	int i;
	printf("Hello...\n");
	for(i=0;i<3;i++)
	{
		if(fork()==0)
			printf("Hai...\n");
		else
			break;
	}
}
