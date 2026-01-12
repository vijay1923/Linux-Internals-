#include"header.h"
void main()
{
	int r,num;
	r=mkfifo("f1",0664);
	perror("mkfifo");
	printf("r=%d\n",r);
	int fd=open("f1",O_WRONLY);
	printf("Enter the nuber \n");
	scanf("%d",&num);
	write(fd,&num,sizeof(int));
	 close(fd);
}
