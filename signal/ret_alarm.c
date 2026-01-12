// Return type of alarm is unsigned int 
// it will return priveous alarm due 

#include"header.h"
void main()
{
	int r;
	printf("Hello ... pid=%d\n",getpid());
	r=alarm(10);
	printf("1) due of r=%d\n",r);// 0 -> priveous due was not there 
	sleep(2);
	r=alarm(5);
	printf("2) due of priveious alarm is r=%d\n",r);   // 8 -> priveous due is 8 sec and 2 sec alrady goes in sleep(2) 
	while(1);

}
