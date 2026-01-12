// Q. perent need to scan the data from user and create one pipe and write into a pipe ,child need to read fro pipe and convert 
// that sring to upper case desplay later on desplay on screen

/*** NOTE: by using 2 pipes we are avioding loopback   ****/

#include"header.h"
void convert(char *p)
{
	int i;
	for(i=0;p[i];i++)
	{
		if(p[i]>='a' && p[i]<='z')
		p[i]=p[i]-32;
	}

}
void main()
{
	int p[2];
	int q[2];
	pipe(p); //create pipe 1
	perror("pipe1:");
	pipe(q); //create pipe 2
	perror("pipe2:");
	printf("p[0]=%d read end of pipe \np[1]=%d write end of pipe\n",p[0],p[1]);
	printf("q[0]=%d read end of pipe \nq[1]=%d write end of pipe\n",q[0],q[1]);
	if(fork()==0)
	{
		char s[10];
		printf("In child before read\n");
		read(p[0],s,sizeof(s)); // child is reading from pipe p
		convert(s);
		write(q[1],s,strlen(s)+1); // child is writing into a pipe q 
		printf("Data: %s\n",s);
	}
	else
	{
		char s[10];
		printf("In perent\nEnter the data\n");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);	// perent is write into a pipe p
		read(q[0],s,sizeof(s));    // perent is reading from pipe q
	}
}
