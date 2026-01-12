#include"header.h"
int main()
{
	FILE *p=fopen("DATA","r");
	if(p==0)
	perror("fopen")	;
	else
	perror("fopen");
}
