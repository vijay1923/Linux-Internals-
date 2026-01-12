// INPUT redirection 
#include"header.h"
void main()
{
	close(0); // close STDIN buffer 
	int fd=open("DATA",O_RDONLY); // sfter closing STDIN open file 
	int a[5],i;
	
	for(i=0;i<5;i++)
	scanf("%d",&a[i]);	// read from file 
	
	for(i=0;i<5;i++)
	printf("%d ",a[i]);	// print it on the screen
	printf("\n");


}
