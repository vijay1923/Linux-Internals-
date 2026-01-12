// CALLING FUNCTIONS THROUGH  --> FUNCTION POINTER

#include<stdio.h>
int sum(int ,int );
int sub(int ,int );
int mul(int ,int );
int div(int ,int );
int main()
{
	int i=20,j=10,k;
	k=sum(i,j);	// normal method to fun call
	printf("k through normal fun call =%d\n",k);

	int (*p)(int ,int ); // Declaring function pointer 
	p=sum;	// sum address given to the function pointer 
	k=(*p)(i,j);	// sum fun calling through fun pointer

//	k=p(i,j);  // valid but it look like normal fun call
 
	printf("k through fun pointer =%d\n",k);

	p=sub;
	k=(*p)(i,j);
	printf("sub : %d\n",k);

	p=mul;
	k=(*p)(i,j);
	printf("mul : %d\n",k);

	p=div;
	k=(*p)(i,j);
	printf("div : %d\n",k);
}

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
int div(int i,int j)
{
	return i/j;
}
