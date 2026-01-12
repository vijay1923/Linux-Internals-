// Q. perent need to scan the data from user and create one pipe and write into a pipe ,child need to read fro pipe and desplay 
// on screen
#include"header.h"
int main()
{
	int p[2];
	pipe(p); //create pipe 
	perror("pipe:");
	printf("p[0]=%d read end of pipe \np[1]=%d write end of pipe\n",p[0],p[1]);
	if(fork()==0)
	{
		char s[10];
		printf("In child before read\n");
		read(p[0],s,sizeof(s));
		printf("Child recived : %s\n",s);
	}
	else
	{
		char s[10];
		printf("In perent\nEnter the data\n");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
	}
}
