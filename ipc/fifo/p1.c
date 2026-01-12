#include"header.h"
void main()
{
	int r;
	mkfifo("f1",0664);
	int fd=open("f1",O_WRONLY);
	char s[10];
	printf("Enter the data\n");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);

}
