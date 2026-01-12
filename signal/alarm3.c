#include"header.h"
FILE *p;
void my_isr(int n)
{
	static char ch='a';
	printf("IN ISR  signalnumber=%d pid=%d\n",n,getpid());
	fputc(ch,p);
	printf("Ch=%c\n",ch);
	if(ch=='z')
	{
		fclose(p);
		raise(9);
	}
	else
	{
		alarm(1);
		ch++;
	}
}
void main()
{
	p=fopen("DATA","a+");
	printf("Hello  pid%d\n",getpid());
	signal(14,my_isr);
	alarm(1);
	while(1);

}
