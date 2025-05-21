CC=gcc
CCFLAGS=-std=c99 -Wall -Wextra -pedantic -g

getmap: getmap.o utils.o
	$(CC) -o $@ $^ 

getmap.o: getmap.c getmap.h
	$(CC) $(CCFLAGS) -c getmap.c

utils.o: utils.c utils.h
	$(CC) $(CCFLAGS) -c utils.c

clean:
	rm -f *.o getmap
