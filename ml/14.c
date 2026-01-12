#include<stdio.h>
#define CUBE(x) x*x*x
void main()
{
int a,b,c;
b=3;
a=CUBE(b++);
b=3;
c=CUBE(++b);
printf("%d %d\n",a,c);
}
