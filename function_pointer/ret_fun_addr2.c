// Assignment 
#include<stdio.h>
/*
char *(*def(int))(int *,char *);
char * abc(int *,char *);
void main()
{
	int i=10;
	char ch='z';
	char *c;
	char *(*p)(int *,char *);
	p=def(100);
	c=(*p)(&i,&ch);
	printf("return char addr : %c\n",*c);


}
char * (*def(int n))(int *,char *)
{
	return abc;
}
char *abc(int *p,char *q)
{
	return q;
}

*/

// Typedef version 
typedef char *(*FPTR)(int *,char *);
FPTR def(int );
char *abc(int *,char *);
void main()
{
	int i=10;
	char ch='z';
	char *c;
	FPTR p;
	p=def(100);
	c=(*p)(&i,&ch);
	printf("return char addr  : %c\n",*c);
}
FPTR def(int n)
{
	return abc;
}
char *abc(int *p,char *q)
{
	return q;
}



