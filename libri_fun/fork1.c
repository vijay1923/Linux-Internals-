#include"header.h"
int main()
{
printf("VIJAY pid=%d\n",getpid());
fork();
fork();
printf("MAGADUM pid=%d\n",getpid());
while(1);
}
