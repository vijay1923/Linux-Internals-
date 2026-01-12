#include"header.h"
int main(int argc,char **argv)
{
	struct stat v;
	stat(argv[1],&v);
	printf("%ld\n",v.st_size);
}
