#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <time.h>
int main() 
{
	int i,p[5];
	int lower = 1, upper = 100;
	srand(getpid());
	for (i = 0; i < 5; i++) 
	{
		 p[i] = (rand() % (upper - lower + 1)) + lower;
		printf("%d \n", p[i]);
	}
}

