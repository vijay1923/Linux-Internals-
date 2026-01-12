// assignment 1: reverse the number 
#include"header.h"
int reverse(int n)
{
	int r,sum=0;
	for(n;n;n=n/10)
	{
		r=n%10;
		sum=sum*10+r;
	}
	return sum;
}
void main()
{
	int p[2];
	int q[2];
	pipe(p); // create pipe p
	perror("pipe p:");
	pipe(q);// create pipe q
	perror("pipe q:");
	printf("p[0]=%d read end of pipe p\np[1]=%d write end of pipe q\n",p[0],p[1]);  // read end and write end of pipe p
	printf("q[0]=%d read end of pipe q\nq[1]=%d write end of pipe q\n",q[0],q[1]);  // read and write end of pipe q

	if(fork()==0)
	{
		int num,rn;
		printf("In child before reverse the number \n");
		read(p[0],&num,sizeof(int ));
		rn=reverse(num);
		write(q[1],&num,sizeof(int ));
		printf("Reverse number is :%d\n",rn);
	}
	else
	{
		int num;
		printf("In perent \nEnter the number you wnat to reverse\n");
		scanf("%d",&num);
		write(p[1],&num,sizeof(int ));
		read(q[0],&num,sizeof(int));
	}
}
