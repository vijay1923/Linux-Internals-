#include"header.h"
void main()
{
	int fd=open("DATA",O_RDONLY);
	printf("fd=%d\n",fd);
	char s[10];
	int r;
//   	bzero(s,sizeof(s));
	memset(s,0,10);
	r=read(fd,s,5);
//	s[r]='\0';
	printf("s=%s\n",s);
	printf("r=%d\n",r);

}
