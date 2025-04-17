CC = gcc
CFLAGS = -Wall -g

all: main

main: temp_api.o main.o
	$(CC) $(CFLAGS) -o main temp_api.o main.o

temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c temp_api.c

main.o: main.c temp_api.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main
