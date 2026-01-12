#include<stdio.h>
void main()
{

char arr[15]="pointer array";
int *ptr;
ptr=(int *)arr;
printf(" %c, %c\n",ptr[1],ptr[2]);

}
