#include"header.h"
void main()
{
int id=shmget(1,20,IPC_CREAT|0664);   // create shared memory
perror("shmget");   // to print error if any while creating
printf("id=%d\n",id);   // print id of shared memory
char *p;
p=shmat(id,0,0);  // attach
perror("shmat");  // to print error if any  while attaching
printf("Enter the string \n");
scanf("%s",p);
}
