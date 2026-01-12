#include"header.h"
void main()
{
	int id=shmget(2,50,IPC_CREAT|0664);
	perror("shmget");
	printf("id=%d\n",id);
	int *p;
	p=shmat(id,0,0);
	perror("shmat");
	printf("Enetr the 5 elements\n ");
	for(int i=0;i<5;i++)
	scanf("%d",&p[i]);

}
