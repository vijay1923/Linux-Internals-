#include"header.h"
int main()
{
	if(fork()==0)
	{
		printf("fork1 if\n");

	}
	else
	{
		printf("Fork1 else\n");
		if(fork()==0)
		{
			printf("fork2 if\n");
		}
		else
		{
			printf("fork2 else\n");
			if(fork()==0)
			{
				printf("fork3 if\n");
			}
			else
			{

				printf("fork3 else\n");
			}
		}

	}
}
