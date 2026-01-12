#include"header.h"
void main(int argc,char **argv)
{
int id=semget(1,5,IPC_CREAT|0644);
perror("semget");
printf("id=%d\n",id);
struct sembuf v;
v.sem_num=2;
v.sem_op=atoi(argv[1]);  // 0,>0,<0
v.sem_flg=SEM_UNDO;
printf("before...\n");
semop(id,&v,1);
printf("After...\n");
}
