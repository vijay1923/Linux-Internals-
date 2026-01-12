#include"header.h"
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
void main()
{
	int id=shmget(2,50,IPC_CREAT|0664);
	perror("shmget");
	printf("id=%d\n",id);
	int *p;
	p=shmat(id,0,0);
	sort(p);
	printf("Sorted array: ");
	for(int i=0;i<5;i++)
	printf("%d ",p[i]);
}
