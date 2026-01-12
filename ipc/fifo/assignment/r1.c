#include"header.h"
void main()
{
	int r,num;
	r=mkfifo("f3",0644);
	perror("mkfifo");
	printf("r=%d\n",r);
	printf("Enter the rollno\n");
	scanf("%d",&num);
	int fd=open("f3",O_WRONLY);
	write(fd,&num,sizeof(int ));
}
