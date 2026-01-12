#include"header.h"
struct msgbuf
{
	long mtype;
	char s[20];
};
void main(int argc,char **argv)
{
	struct msgbuf v;
	int id=msgget(1,IPC_CREAT|0644);
	perror("msgget");
	printf("id=%d\n",id);
	v.mtype=atoi(argv[1]);
	strcpy(v.s,argv[2]);
	msgsnd(id,&v,strlen(v.s)+1,0);
}
