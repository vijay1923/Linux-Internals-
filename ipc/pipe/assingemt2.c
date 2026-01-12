#include"header.h"
void sort(int *p)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(p[i]<p[j])
			{
				int t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
}
void main()
{
	int p[2];
	int q[2];
	pipe(p); // creat pipe p
	perror("pipe p:");
	pipe(q); // creat pipe q
	perror("pipe q:");
	printf("p[0]=%d read end of pipe p\np[1]=%d write end of pipe q\n",p[0],p[1]); // read and erite end of pipe p
	printf("q[0]=%d read end of pipe q\nq[1]=%d write end of pipe q\n",q[0],q[1]); // read and erite end of pipe q

	if(fork()==0)
	{
		int a[10];
		printf("In child before the sorting \n");
		read(p[0],a,sizeof(a));
		write(q[1],a,sizeof(a));
		sort(a);
		for(int i=0;i<5;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
	else
	{
		int a[10];
		printf("In perent Enter the array\n");
		for(int i=0;i<5;i++)
		scanf("%d",&a[i]);
		write(p[1],a,sizeof(a));
		read(q[0],a,sizeof(a));
	}
}
