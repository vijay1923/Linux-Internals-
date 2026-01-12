#include"header.h"
struct st
{
	int rollno;
	char name[20];
	float marks;
};
struct msgbuf
{
	long mtype;
	int rollno;
};
void main(int argc,char **argv)
{
	int id=msgget(3,IPC_CREAT|0664);
	perror("msgget");
	printf("id=%d\n",id);
	struct msgbuf v;
	struct st s;
	msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
	FILE *fp=fopen("data","r");
	while(fscanf(fp,"%d %s %f",&s.rollno,s.name,&s.marks)!=-1)
	{
		if(v.rollno==s.rollno)
		{
			printf("%d %s %f\n",s.rollno,s.name,s.marks);
		}
	}

}
