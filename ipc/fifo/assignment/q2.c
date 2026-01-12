#include"header.h"
void sort(int *a)
{
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			if(a[i]>a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
void main()
{
	int r,a[10];
	//	r=mkfifo("f2",0644);
	//	perror("mkfifo");
	//	printf("r=%d\n",r);
	int fd=open("f2",O_RDONLY);
	read(fd,a,sizeof(a));
	sort(a);
	printf("Sorted array\n");
	for(int i=0;i<5;i++)
	printf("%d ",a[i]);
	printf("\n");

}
