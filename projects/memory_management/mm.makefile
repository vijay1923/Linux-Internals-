CC = gcc
CFLAGS = -Wall -g

all: mm

mm: main.c header.h
	$(CC) $(CFLAGS) -o mm main.c

clean:
	rm -f mm
