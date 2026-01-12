#include"header.h"
int main()
{
// case 1
/*
printf("Hello...");
fork();
printf("Hai...");
while(1);
*/
/* case 2
printf("Hello...");
fork();
printf("Hai...\n");
while(1);
// op-> Hello...Hai...
//        Hello...Hai...
*/

/* case 3
printf("Hello...\n");
fork();
printf("Hai...\n");
while(1);
*/

/* case 4
printf("Hello...\n");
fork();
printf("Hai...");
while(1);
*/

// case 5
printf("Hello...");
printf("\n");
fork();
printf("Hai");
while(1);
}
