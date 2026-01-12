#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_alarm(int sig) 
{
    printf("Alarm triggered every 1 second!\n");
    alarm(1);
}

int main() 
{
    signal(SIGALRM, handle_alarm);
    alarm(1);
    while (1);  // No pause(), just an infinite loop
    return 0;
}

