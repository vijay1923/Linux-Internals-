#include"header.h"
void main()
{
int id=shmget(3,4,IPC_CREAT|0664);
perror("shmget");
printf("id=%d\n",id);
int *p;
p=shmat(id,0,0);
printf("Enetr the rollno\n");
scanf("%d",p);
}
