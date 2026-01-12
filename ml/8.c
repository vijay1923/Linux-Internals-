#include<stdlib.h>
#include<stdio.h>
void main()
{
printf("first\n");
fork();
printf("second\n");
fork();
printf("third\n");
exit(0);

}
