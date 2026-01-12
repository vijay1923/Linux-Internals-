#include"header.h"
int main()
{
	int a[10],i;
	srand(getpid());
	for(i=0;i<5;i++)
//	a[i]=rand()%100+1; // generating random numbers bet 1 to 100
//	a[i]=rand()%51+50;  // bet 50 to 100
	a[i]=rand()%900+100;	// bet 100 to 999   only 3 digit numbers  
	for(i=0;i<5;i++)
	printf("%d ",a[i]);
	printf("\n");
}
