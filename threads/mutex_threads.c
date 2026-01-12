#include "header.h"
pthread_t t1,t2,t3;
pthread_mutex_t m1,m2,m3;
void *fun_num (void *p) // writing digits 
{
        char i;
        for(i=1;i<=26;++i)
        {
                pthread_mutex_lock(&m1);  // set lock to m1 
                printf("%d\t",i);
                fflush(stdout);
		sleep(1);
                pthread_mutex_unlock(&m2);  // unlock the m2 to write capital alphabate 
        }
        pthread_exit(0);
}
void *fun_cap (void *p) // writing capital alphabates 
{
        char i;
        for(i='A';i<='Z';++i)
        {
                pthread_mutex_lock(&m2); // set lock to a m2
                printf("%c\t",i);
                fflush(stdout);
		sleep(1);
                pthread_mutex_unlock(&m3); // unlock m3 to write small alphabate 
        }
        pthread_exit(0);
}
void *fun_sml (void *p) // writing small alphabates
{
        char i;
        for(i='a';i<='z';++i)
        {
                pthread_mutex_lock(&m3);  // set a lock to a m3 
                printf("%c\n",i);
		sleep(1);
                pthread_mutex_unlock(&m1);  // unlock the m1 to write again digits 
        }
        pthread_exit(0);
}
void mutex_init(void )
{
        pthread_mutex_init(&m1,NULL);  // 
        pthread_mutex_init(&m2,NULL);
        pthread_mutex_init(&m3,NULL);
        pthread_mutex_lock(&m2);  // set lock to m2
        pthread_mutex_lock(&m3); // set lock to m3
}
void main()
{
        mutex_init();  // craete 3 mutex 
        pthread_create(&t1,NULL,fun_num,NULL); 
        pthread_create(&t2,NULL,fun_cap,NULL);
        pthread_create(&t3,NULL,fun_sml,NULL);
        pthread_exit(0);  // after creating 3 threads main thread exits

}
