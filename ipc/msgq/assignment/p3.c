#include"header.h"
struct msgbuf
{
	long mtype;
	int a[10];
};
void main(int argc,char **argv)
{
	int id=msgget(2,IPC_CREAT|0664);// ./a.out msgtyp
	perror("msgget");
	printf("id=%d\n",id);
	struct msgbuf v;
	v.mtype=atoi(argv[1]);
	printf("Enter the 5 elements of an array\n");
	for(int i=0;i<5;i++)
	scanf("%d",&v.a[i]);
msgsnd(id,&v,sizeof(v.a),0);
perror("msgsnd");
}
