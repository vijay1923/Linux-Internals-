#include<unistd.h>
#include<pthread.h> 
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
            
void *thread_1(void *p)
{
    while(1)
    printf("In thread_1 pid=%d tid=%lu\n", getpid(), (unsigned long)pthread_self());
}
void *thread_2(void *p)
{
    while(1)
    printf("In thread_2 pid=%d tid=%lu\n", getpid(), (unsigned long)pthread_self());
}
void *thread_3(void *p)
{
    while(1)
    printf("In thread_3 pid=%d tid=%lu\n", getpid(), (unsigned long)pthread_self());
}
void main()
{
    pthread_t t1,t2,t3; 
    pthread_create(&t1,0,thread_1,"Thread 1");	// creat a thred and pass on string to that thread
    pthread_create(&t2,0,thread_2,"Thread 2");	// creat a thred and pass on string to that thread		
    pthread_create(&t3,0,thread_3,"Thread 3");	// creat a thred and pass on string to that thread
    pthread_detach(t1);	// detach the thread so that its resources are freed on termination
    pthread_detach(t2);	// detach the thread so that its resources are freed on termination
    pthread_detach(t3);	// detach the thread so that its resources are freed on termination 		
    while(1)
    printf("In main pid=%d tid =%ld\n",getpid(),pthread_self()); // pid and thread id

}
