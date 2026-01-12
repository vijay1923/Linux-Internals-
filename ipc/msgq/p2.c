#include"header.h"
struct msgbuf
{
	long mtype;
	char s[20];
};
void main(int argc,char **argv)
{
	int id=msgget(1,IPC_CREAT|0664);
	perror("msgget");
	printf("id=%d\n",id);
	struct msgbuf v;
	msgrcv(id,&v,sizeof(v.s),atoi(argv[1]),0);
	printf("DATA=%s\n",v.s);
}
