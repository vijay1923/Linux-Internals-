// WRITE A PROGRAM WHEN EVER CNTL + C SIGNAL COMES THEN EXECUTE ISR 
#include"header.h"
void my_isr(int n)
{
printf("In ISR  signal number = %d  pid = %d\n",n,getpid());
}
void main()
{
printf("Hello ... pid=%d\n",getpid());
signal(SIGINT,my_isr);
printf("Hai...\n");
while(1);

}
