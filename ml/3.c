#include<stdio.h>
void main()
{
char num_char[16]="1A2B3C4D5E6F7G8";
int *_linux;
_linux=(char *)num_char;
printf("%c\n",_linux[2]);
}
