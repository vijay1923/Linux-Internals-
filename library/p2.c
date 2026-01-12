#include<stdio.h>
int main()
{
	int num;
	printf("Enter the number to check num if prime or not \n");
	scanf("%d",&num);
	int i;
	for(i=2;i<=num;i++)
	{
		if(num%i==0)
			break;
	}
	if(i==num)
	printf("Given number is prime number \n");
	else
	printf("Given number is not prime number\n");
}
