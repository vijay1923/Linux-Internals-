// craeting thread in one process  
#include"header.h"
void * thread_1(void *p)
{
	while(1)
	//printf("%s\n",(char *)p);
	printf("In thread_1 pid=%d tid=%ld\n",getpid(),pthread_self()); // pid and thread id 
}
void * thread_2(void *p)
{
	while(1)
	printf("In thread_2 pid=%d tid=%ld\n",getpid(),pthread_self()); // pid and thread id 
}
void main()
{
	pthread_t t1,t2; 
	pthread_create(&t1,0,thread_1,"Thread 1");	// creat a thred and pass on string to that thread
	pthread_create(&t2,0,thread_2,"Thread 2");	// creat a thred and pass on string to that thread		
	while(1)
	printf("In main pid=%d tid =%ld\n",getpid(),pthread_self()); // pid and thread id 

}

