#include"header.h"
FILE *p;
void my_isr(int n)
{
	p=fopen("DATA","a");
	for(char ch='A';ch<='Z';ch++)
	fputc(ch,p);
	fclose(p);
}
void main()
{
	int r;
	r=fork();
	if(r==0)
	{
		signal(SIGUSR1,my_isr);
		pause();
	}
	else
	{
		p=fopen("DATA","r");
		for(char ch='a';ch<='z';ch++)
		fputc(ch,p);
		fclose(p);
		kill(r,SIGUSR1);
	}
}
