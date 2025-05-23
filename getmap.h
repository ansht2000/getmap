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

uint8_t *header(int s, in_addr_t ip);
bool tcpConnect(in_addr_t ip, uint16_t port);
in_addr_t generate();

int main(int argc, char **argv);