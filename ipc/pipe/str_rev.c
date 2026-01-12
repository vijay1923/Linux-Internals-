#include"header.h"
void rev(char *p)
{
	int i,j,l;
	for( l=0;p[l];l++);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		char t=p[i];
		p[i]=p[j];
		p[j]=t;
	}
	printf("REV STRING : %s\n",p);
}
void main()
{
	int p[2],q[2];
	pipe(p);
	perror("pipe p");
	pipe(q);
	perror("pipe q");
	if(fork()==0)
	{
		char s[50];
		read(p[0],s,sizeof(s));
		rev(s);
		write(q[1],s,strlen(s)+1);

	}
	else
	{
		char s[50];
		printf("Enter the string \n");
		scanf("%[^\n]",s);
		write(p[1],s,strlen(s)+1);
		read(q[0],s,sizeof(s));
	}
}
