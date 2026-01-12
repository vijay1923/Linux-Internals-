#include"header.h"
int main()
{
	if(fork()==0)
		printf("Hello..\n");
	else
	{
		sleep(5);
		printf("Hai...\n");
	}

}
