#include"header.h"
struct msgbuf
{
	long mtype;
	int rollno;
};
int revnum(int n)
{
	int r,sum=0;
	for(n;n;n=n/10)
	{
		r=n%10;
		sum=sum*10+r;
	}
	return sum;
}
void main(int argc,char **argv)
{
	int rn;
	int id=msgget(1,IPC_CREAT|0644);
	perror("msgget");
	printf("id=%d\n",id);
	struct msgbuf v;
	msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
	rn=revnum(v.rollno);
	printf("Reversed number : %d\n",rn);
}
