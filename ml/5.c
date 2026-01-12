#include<stdio.h>
void main()
{
int k=125;
char *i=(char *)&k;
for( ;*i>0;++*i);
printf("%d\n",*i);

}
