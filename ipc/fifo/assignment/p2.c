#include"header.h"
int reverse(int num)
{
	int sum=0,r;
	for(num;num;num=num/10)
	{
		r=num%10;
		sum=sum*10+r;
	}
	return sum;
}
void main()
{
	int r,num,rn;
	r=mkfifo("f1",0664);
	perror("mkfifo");
	printf("r=%d\n",r);
	int fd=open("f1",O_RDONLY);
	read(fd,&num,sizeof(int));
	rn=reverse(num);
	printf("reverse number :%d\n",rn);
}
