#include"header.h"
void main()
{
int id=shmget(1,4,IPC_CREAT|0664);
perror("shmget");
printf("id=%d\n",id);
int *p;
p=shmat(id,0,0);
perror("shmat");
printf("Enter the number\n");
scanf("%d",p);
}
