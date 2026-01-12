#include"header.h"
void main()
{

	//FILE *fp=fopen("DATA","r");

	//int fd=open("DATA",O_RDONLY);


	//FILE *fp=fopen("DATA","w");
	//int fd=open("DATA",O_WRONLY|O_TRUNC|O_CREAT,0664);


	//FILE *fp=fopen("DATA","a");
	//int fd=open("DATA",O_WRONLY|O_APPEND|O_CREAT,0664);

	int fd=open("data",O_RDONLY);
	if(fd<0)
	{
		perror("open  open sys call ");  // if file not found 
		return;
	}
	printf("fd=%d\n",fd);

}










