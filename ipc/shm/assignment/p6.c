#include"header.h"
struct st
{
	int rollno;
	char name[20];
	float marks;
};
void main()
{
	int id=shmget(3,4,IPC_CREAT|0644);
	perror("shmget");
	printf("id=%d\n",id);
	int *p;
	p=shmat(id,0,0);
	struct st v;
	FILE *fp=fopen("data","r");
	while(fscanf(fp,"%d %s %f",&v.rollno,v.name,&v.marks)!=-1)
	{
		if(*p==v.rollno)
		{
			printf("%d %s %f\n",v.rollno,v.name,v.marks);
			break;
		}
	}

}
