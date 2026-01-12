#include"header.h"
void abc(void )
{
	printf("In abc function\n");
}
int main()
{
	printf("Hello  pid=%d\n",getpid());
	atexit(abc);
	printf("Hai..\n");
	sleep(20);
	printf("Bye...\n");
	exit(0);

}
