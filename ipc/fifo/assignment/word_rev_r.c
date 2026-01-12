#include"header.h"
char *my_strchr(char *p,char ch)
{
	while(*p)
	{
		if(*p==ch)
			return p;
		p++;
	}
}
void strrev(char *p,char *q)
{
	while(p<q)
	{
		char t=*p;
		*p=*q;
		*q=t;
		p++;
		q--;
	}

}
void rev(char *s)
{
int l;
	char *p,*q;
	p=s;
	while(q=my_strchr(p,' '))
	{
		strrev(p,q);
		p=q+1;
	}
#if 0
	for(l=0;p[l];l++);
	for(int i=0,j=l-1;i<j;i++,j--)
	{
		char t=p[i];
		p[i]=p[j];
		p[j]=t;
	}
#endif
}
void main()
{
	mkfifo("f1",0644);
	int fd=open("f1",O_RDONLY);
	char s[50];
	read(fd,s,sizeof(s));
	rev(s);
	printf("DATA : %s\n",s);
}

