#include"header.h"
struct A
{
	char f_name[20];
	char ch;
};
void * thread_1(void *p)
{
	struct A *a = (struct A *)p;	
	char ch1;
	int c=0;
	FILE *fp=fopen(a->f_name,"r");
	while((ch1=fgetc(fp))!=EOF)
	{
		if(ch1==a->ch)
			c++;
	}
	printf("Charactre count :%d\n",c);

}
void main(int argc,char **argv)
{

	if(argc!=3)
	{
		printf("Usage:./a.out fname char\n");
		return;
	}
	struct A a1;
	strcpy(a1.f_name,argv[1]);
	a1.ch=argv[2][0];
	pthread_t t1;
	pthread_create(&t1,0,thread_1,&a1);
	pthread_exit(0);
}

