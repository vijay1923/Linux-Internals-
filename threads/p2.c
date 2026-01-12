#include"header.h"
void * thread_1(void *p)
{
	while(1)
	printf("%s\n",(char *)p);
	//printf("In thread_1 pid=%d tid=%ld\n",getpid(),pthread_self());
}
void main()
{

	pthread_t t1;
	pthread_create(&t1,0,thread_1,"Hello");

	//while(1)
	printf("In main pid=%d tid =%ld\n",getpid(),pthread_self());
	pthread_exit(0);	// you want to thread to run then use pthread_exit(0);  * it is like main in while one 

}

