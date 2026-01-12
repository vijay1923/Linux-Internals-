// here task1 and task2 are executing concurrently 
#include"header.h"
void task1(void )
{
	while(1)
	printf("Task 1\n");
}
void task2(void )
{
	while(1)
	printf("Task 2\n");
}
int main()
{
	int r;
	r=fork();
	if(r==0)
	task1();
	else
	task2();
}
