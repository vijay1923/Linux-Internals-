#include"header.h"
void main()
{
	int r;
	r=mkfifo("f1",0664);
	perror("mkfifo");
	printf("r=%d\n",r);
	int fd=open("f1",O_RDONLY);
	char s[10];
	read(fd,s,sizeof(s));
	printf("S=%s\n",s);
}
