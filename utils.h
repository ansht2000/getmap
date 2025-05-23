#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// DOES NOT WORK FOR ARRAYS PASSED TO A FUNCTION
#define arrlen(x) (sizeof(x) / sizeof((x)[0]))

typedef __ssize_t ssize_t;
typedef int fd_t;

// get a string from fgets without the newline
char *lfgets(char *restrict s, int n, FILE *restrict stream, size_t limit);
ssize_t lread(int fd, void *buf, size_t nbytes, in_addr_t ip);

#endif