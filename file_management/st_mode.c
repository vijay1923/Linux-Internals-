#include"header.h"
void main(int argc,char **argv)
{
	struct stat v;
	stat(argv[1],&v);
	printf("file type :%u\n",v.st_mode);
	printf("file permissions :%u\n",v.st_mode&0777);
	if(S_ISREG(v.st_mode))
	printf("Reguler file...\n");
	else if(S_ISDIR(v.st_mode));
	printf("Directry file...\n");
}
