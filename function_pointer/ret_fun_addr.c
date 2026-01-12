// Q. Design a function which return sum function addr
#include<stdio.h>
/*
int sum(int ,int );
int (*ret_fun_addr(void ))(int ,int ); 
int main()
{
	int i=10,j=20,k;
	int (*p)(int ,int );
	p=ret_fun_addr();
	k=(*p)(i,j);
	printf("K=%d\n",k);
}
int (*ret_fun_addr(void ))(int ,int )
{
	return sum;
}
int sum(int i,int j)
{
	return 100;
}

*/

typedef (*FPTR)(int ,int );
FPTR ret_fun_addr(void );
int sum(int ,int );
void main()
{
	int i=10,j=20,k;
	FPTR p;
	p=ret_fun_addr();
	k=(*p)(i,j);
	printf("K=%d\n",k);
}
FPTR ret_fun_addr(void )
{
	return sum;
}
int sum(int i,int j)
{
	return 200;
}
