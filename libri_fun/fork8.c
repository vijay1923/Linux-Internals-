#include"header.h"
int main()
{
	if(fork()==0)
	system("ls");
	else
	system("pwd");
	while(1);
}
