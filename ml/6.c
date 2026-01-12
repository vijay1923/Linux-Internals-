#include<stdio.h>
void main(){
	struct bitfield
	{
		unsigned int a:5;
		unsigned int c:5;
		unsigned int b:6;
	}bit;
	char *p;
	struct bitfield *ptr,bit1={1,2,3};
	p=&bit1;
	++p;
	printf("%d ",*p);
	--p;
	printf("%d\n",*p);

}
