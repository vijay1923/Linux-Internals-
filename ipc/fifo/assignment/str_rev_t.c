#include"header.h"
void main()
{ 
	mkfifo("f1",0644);
	perror("mkfifo");
	int fd=open("f1",O_WRONLY);
	char s[50];
	printf("Enter the string \n");
	scanf("%[^\n]",s);
	write(fd,s,strlen(s)+1);
}
