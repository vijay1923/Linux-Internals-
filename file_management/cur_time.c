// Print current time and date using time fun
#include"header.h"
void main()
{
	time_t t;
	while(1)
	{
		printf("Enter the seconds\n");
		scanf("%ld",&t);
//		time(&t); 
//		printf("%lu\n",t);  // time in sec from 1970 ti till now 
		printf("%s\n",ctime(&t));  // give human readable timr string 
		sleep(1);
		system("clear");
	}

}
