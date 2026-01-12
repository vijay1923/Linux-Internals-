#include"header.h"
void main(int argc,char **argv)
{
	int id=semget(1,5,IPC_CREAT|0664);
	perror("semget");
	printf("id=%d\n",id);
	int r=semctl(id,atoi(argv[1]),GETVAL);	// ./a.out semnum
	perror("semctl");
	printf("r=%d\n",r);

}
