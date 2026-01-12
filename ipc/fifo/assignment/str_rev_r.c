#include"header.h"
void rev(char *p)
{
	int i,j;
	int l=strlen(p);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		char t=p[i];
		p[i]=p[j];
		p[j]=t;
	}

}
void main()
{ 
	mkfifo("f1",0644);
	perror("mkfifo");
	int fd=open("f1",O_RDONLY);
	char s[50];
	read(fd,s,sizeof(s));
	rev(s);
	printf("DATA:%s\n",s);
}
