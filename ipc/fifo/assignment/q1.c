// Q. Sort the array
#include"header.h"
void main()
{
	int r,a[10];
	r=mkfifo("f2",0664);
	perror("mkfifo");
	printf("r=%d\n",r);
	int fd=open("f2",O_WRONLY);
	printf("Enter the elements of array\n");
	for(int i=0;i<5;i++)
	scanf("%d",&a[i]);
	write(fd,a,sizeof(a));
}
