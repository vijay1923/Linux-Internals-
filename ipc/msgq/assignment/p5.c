#include"header.h"
struct msgbuf
{
long mtype;
int rollno;
};
void main(int argc,char **argv)
{
int id=msgget(3,IPC_CREAT|0664);
perror("msgget");
printf("id=%d\n",id);
struct msgbuf v;
v.mtype=atoi(argv[1]);
printf("Enetr the Rollno\n");
scanf("%d",&v.rollno);
msgsnd(id,&v,sizeof(v.rollno),0);
perror("msgsnd");

}
