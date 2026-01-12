// Q. Perent need to scan rollno from user and write it into a pipe , child should read that rollno and serch that rollno in a file and if
// found then print that sudent data 

#include"header.h"
struct st
{
	int rollno;
	char name[20];
	float mark;
};
void main()
{

	struct st s;
	int p[2];
	int q[2];
	pipe(p);// creat pipe p
	perror("pipe p:");
	pipe(q);// creat pipe q
	perror("pipe q:");
	printf("p[0]=%d read end of pipe p\np[1]=%d write end of pipe p\n",p[0],p[1]);// read and write end of pipe p
	printf("q[0]=%d read end of pipe q \nq[1]=%d write end of pipe q\n",q[0],q[1]);// read and write end of pipe q

	if(fork()==0)
	{
		int n;
		printf("In child\n");
		read(p[0],&n,sizeof(n));
		write(q[1],&n,sizeof(int));
		FILE *fp=fopen("data","r");
		while (fscanf(fp,"%d %s %f", &s.rollno, s.name, &s.mark) != EOF)
		{
			if(s.rollno==n)
			{
				printf("%d %s %f\n",s.rollno,s.name,s.mark);
				break;
			}
printf("Rollno not found \n");
		}
	}
	else
	{
		int rn;
		printf("In perent \nEnter the rollno\n");
		scanf("%d",&rn);
		write(p[1],&rn,sizeof(rn));
		read(q[0],&rn,sizeof(int));
	}
}
