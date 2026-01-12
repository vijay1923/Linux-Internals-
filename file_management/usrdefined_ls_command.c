// User defined ls command 
// provide ./a.ot .
#include"header.h"
void main(int argc,char **argv)
{
	DIR *dp=opendir(argv[1]);
	struct dirent *p;
	while(p=readdir(dp))
	if(p->d_name[0]!='.')
	printf("%s\n",p->d_name);

}
