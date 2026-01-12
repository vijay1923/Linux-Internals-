#include"header.h"
int main()
{
	if(fork()==0)
	{
		printf("fork1 \n");
		if(fork()==0)
		{
			printf("fork2 \n");
			if(fork()==0)
			{
				printf("fork3 \n");
			}
		}
	}
while(1);
}
