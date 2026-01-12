#include"header.h"
void my_isr(int n)
{
	printf("IN ISR  signal no=%d || signal describe:%s\n",n,strsignal(n));
}
void main()
{
	struct sigaction v;
	v.sa_handler=my_isr;
	sigemptyset(&v.sa_mask);
	v.sa_flags=SA_RESETHAND;
	sigaction(SIGXCPU,&v,0);

	struct rlimit s;
	getrlimit(RLIMIT_CPU,&s);
	s.rlim_cur=5;  // set new cpu soft limit
	setrlimit(RLIMIT_CPU,&s);

	while(1);
}
