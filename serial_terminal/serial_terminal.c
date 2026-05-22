#include <stdio.h> 
#include <fcntl.h>  
#include <termios.h>  // 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#include <errno.h> 

#define SERIAL_PORT "/dev/ttyUSB0"
// #define SERIAL_PORT "/dev/ttyUSB1"
// #define SERIAL_PORT "/dev/ttyUSB2"

#define BAUDRATE B115200   // 115200_8N1
// #define BAUDRATE B9600   // 9600_8N1


int main(int argc , char** argv )
{
    int serial_fd; // file descriptor for the serial port

    serial_fd = open(SERIAL_PORT, O_RDWR); // open the serial port for reading and writing

    if (serial_fd < 0)
    {
        printf("Error opening %s: %s\n", SERIAL_PORT, strerror(errno));
        return 1;
    }

    struct termios tty; // variable to hold the serial port settings

    if (tcgetattr(serial_fd, &tty) != 0)
    {
        printf("Error from tcgetattr\n");
        return 1;
    }

    /* Configure serial */

    cfsetispeed(&tty, BAUDRATE); // set input baud rate
    cfsetospeed(&tty, BAUDRATE); // set output baud rate

    tty.c_cflag &= ~PARENB; // disable parity
    tty.c_cflag &= ~CSTOPB; // set 1 stop bit
    tty.c_cflag &= ~CSIZE;  // clear current character size mask
    tty.c_cflag |= CS8;     // set 8 data bits

    tty.c_cflag |= CREAD | CLOCAL;  // enable receiver, ignore modem control lines
    tty.c_cflag &= ~CRTSCTS;   // disable hardware flow control

    tty.c_lflag = 0; // set raw input mode
    tty.c_oflag = 0; // set raw output mode
    tty.c_iflag = 0; // set raw input mode (no special handling of bytes)

    tty.c_cc[VMIN]  = 1; // read blocks until at least 1 byte is available
    tty.c_cc[VTIME] = 0;  // no timeout, read blocks indefinitely until at least 1 byte is available

    if (tcsetattr(serial_fd, TCSANOW, &tty) != 0) // if setting the attributes fails, print an error message and exit
    {
        printf("Error from tcsetattr\n");
        return 1;
    }

    printf("Listening on %s\n", SERIAL_PORT); // print a message indicating which serial port is being listened to

    char buffer[1]; // buffer to hold incoming bytes
    char line[512];  // buffer to hold the current line being read
    int index = 0; // index to keep track of the current position in the line buffer

    while (1)
    {
        int n = read(serial_fd, buffer, 1); // read one byte from the serial port into the buffer

        if (n > 0)
        {
            char c = buffer[0];

            if (c == '\r') // ignore carriage return characters
                continue;

            if (c == '\n')  // if a newline character is received, print the line with a timestamp and reset the index for the next line
            {
                line[index] = '\0';

                time_t now = time(NULL);  // get the current time
                struct tm *t = localtime(&now); // structer variable to  convert the current time to local time structure

                printf("[%02d:%02d:%02d] %s\n",t->tm_hour,t->tm_min,t->tm_sec,line); // print the timestamp and the line received from the serial port
                fflush(stdout); 

                index = 0; // make sure to reset the index for the next line
            }
            else
            {
                if (index < sizeof(line) - 1) // if the line buffer is not full, add the character to the line buffer
                {
                    line[index++] = c; // add the character to the line buffer and increment the index
                }
            }
        }
    }

    close(serial_fd); // at last close the serial port before exiting the program
}
