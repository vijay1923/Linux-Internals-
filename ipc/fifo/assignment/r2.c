#include"header.h"
struct st
{
	int rollno;
	char name[20];
	float mark;
};
struct st p;
void main()
{
	int r,num,rn;
	r=mkfifo("f3",0644);
	perror("mkfifo");
	printf("r=%d\n",r);
	int fd=open("f3",O_RDONLY);
	read(fd,&num,sizeof(int));
	FILE *fp=fopen("data","r");
	while(fscanf(fp,"%d %s %f",&p.rollno,p.name,&p.mark)!=EOF)
	{
		if(p.rollno==num)
		{
			printf("%d %s %f\n",p.rollno,p.name,p.mark);
			break;
		}
	}
}
