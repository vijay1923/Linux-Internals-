#include"header.h"
int main()
{
int r;
printf("Hello  pid=%d\n",getpid());
r=fork();
printf("Hai   r=%d  pid=%d\n",r,getpid());

}
