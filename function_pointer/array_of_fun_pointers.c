// array of function pointers 
#include<stdio.h>
typedef int (*FPTR )(int ,int );
int sum(int i,int j)
{
	return i+j;
}
int sub(int i,int j)
{
	return i-j;
}
int mul(int i,int j)
{
	return i*j;
}
int dive(int i,int j)
{
	return i/j;
}
int main()
{
	int i=10,j=20,k;
	FPTR p[4]={sum,sub,mul,dive};
	for(k=0;k<4;k++)
	printf("%d\n",(p[k])(i,j));

}
