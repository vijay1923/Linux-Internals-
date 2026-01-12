#include <stdlib.h>
#include <stdio.h>
int main()
 {
	int status;
	status = system("ls -l"); // Lists files in the current directory
	if (status == -1)
	{
		perror("system");
	} 
	else
	{
		printf("Command executed with status: %d\n", status);
	}
	return 0;
}

