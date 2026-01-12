#include"header.h"
struct msgbuf
{
	long mtype;
	int rollno;
};
void main(int argc,char **argv)
{
	int num;
	int id=msgget(1,IPC_CREAT|0644);
	perror("msggwt");
	printf("id=%d\n",id);
	struct msgbuf v;
	v.mtype=atoi(argv[1]);
	v.rollno=atoi(argv[2]);
	msgsnd(id,&v,sizeof(int ),0);

}
