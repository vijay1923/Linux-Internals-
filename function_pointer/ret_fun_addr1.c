// Q. design a fun which takes 2 aur (in ,chra) which return addr of another fun which takes 2 aur (int ,float )and return int .
#include<stdio.h>
/*
int (*mno(int ,char ))(int ,float );
int dummy(int ,float );
void main()
{
	int k;
	int (*p)(int ,float );
	p=mno(100,'a');
	k=(*p)(10,20.20);
	printf("k=%d\n",k);
}
int (*mno(int i,char ch))(int ,float )	
{
	return dummy;
}
int dummy(int i,float f) 
{
	return 500;
}
*/

// Typedef version 

typedef int (*FPTR )(int ,float );
FPTR mno(int ,char  );
int dummy(int ,float );
void main()
{
	int k;
	FPTR p;
	p=mno(100,'v');
	k=(*p)(50,12.5);
	printf("k=%d\n",k);
}
int dummy(int i,float f)
{
	return 12345;
}
FPTR mno(int i,char ch)
{
	return dummy;
}
