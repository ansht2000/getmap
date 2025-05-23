#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// struct to hold the current and final specified IP addresses
typedef struct _ip_addrs {
    in_addr_t current;
    in_addr_t ending;
    uint16_t port;
} IPAddrs;

in_addr_t generate();

int main(int argc, char **argv);