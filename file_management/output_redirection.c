// OUTPUT redirection 
#include"header.h"
void main()
{
	close(1);// close STDOUT buffer
	int fd=open("DATA",O_WRONLY|O_CREAT|O_TRUNC);  // after closing STDOUT open file 
	int a[5]={10,20,30,40,50},i;
	for(i=0;i<5;i++)
	printf("%d ",a[i]);  /// printf will write into file not on screen
}
