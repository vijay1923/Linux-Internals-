#include<stdio.h>
void main()
{
char *c[]={"india","Aus","Eng","woeldcup"};
char **cp[]={c+3,c+2,c+1,c};
char ***cpp;
cpp=cp;
cpp++;
printf("%s\n",*--*++cpp);

}
