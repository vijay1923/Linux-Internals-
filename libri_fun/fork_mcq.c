// mcq on fork() 
#include"header.h"
int main()
{
	if(fork() && fork())
		fork();
	printf("Hello\n");
}
