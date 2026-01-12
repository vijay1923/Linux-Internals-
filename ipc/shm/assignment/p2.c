#include"header.h"
int rev(int num)
{
	int sum=0,r;
	for(num;num;num=num/10)
	{
		r=num%10;
		sum=sum*10+r;
	}
	return sum;
}
void main()
{
	int id=shmget(1,4,IPC_CREAT|0664);
	perror("shmget");
	printf("id=%d\n",id);
	int *p;
	p=shmat(id,0,0);
	int rn=rev(*p);
	printf("Reversed number : %d\n",rn);
}
