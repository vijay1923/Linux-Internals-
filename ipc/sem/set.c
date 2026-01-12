#include"header.h"
void main(int argc,char **argv)
{
int id=semget(1,5,IPC_CREAT|0664);
perror("semget");
printf("id=%d\n",id);
semctl(id,atoi(argv[1]),SETVAL,atoi(argv[2]));
perror("semctl");
}
