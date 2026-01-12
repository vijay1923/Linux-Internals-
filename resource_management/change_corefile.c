// change core files size 
#include"header.h"
void main()
{
struct rlimit v;
getrlimit(RLIMIT_CORE,&v);
printf("Core file size:- soft limit:%u || hard limit:%u\n",(int)v.rlim_cur,(int)v.rlim_max);

v.rlim_cur=1000;  // set new soft limit for the core files
setrlimit(RLIMIT_CORE,&v);

getrlimit(RLIMIT_CORE,&v);
printf("Core file size:- soft limit:%u || hard limit:%u\n",(int)v.rlim_cur,(int)v.rlim_max);
}
