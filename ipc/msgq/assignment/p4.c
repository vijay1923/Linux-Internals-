#include"header.h"
struct msgbuf
{
	long mtype;
	int a[10];
};
void sort(int *p)
{
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			if(p[i]>p[j])
			{
				int t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
}
void main(int argc,char **argv)
{
	int id=msgget(2,IPC_CREAT|0664);
	perror("msgget");
	printf("id=%d\n",id);
	struct msgbuf v;
	msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
	perror("msgrcv");
	sort(v.a);
	printf("Sorted array:");
	for(int i=0;i<5;i++)
	printf("%d ",v.a[i]);

}
