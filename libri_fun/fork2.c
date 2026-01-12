#include"header.h"
int main()
{
printf("Hello pid=%d\n",getpid());
fork();
fork();
fork();
printf("Hai.. \n");
while(1);

}
