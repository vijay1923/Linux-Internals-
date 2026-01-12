#include"header.h"
void abc(void )
{
printf("In abc function...\n");
}
int main()
{
printf("Hello   pid=%d\n",getpid());
atexit(abc);
printf("Hai...\n");
sleep(10);
printf("Bye...\n");
_exit(0);
}
