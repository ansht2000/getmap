#include "getmap.h"

in_addr_t generate(IPAddrs *addrs) {
    if (addrs->current >= addrs->ending) {
        return (in_addr_t)0;
    }
    addrs->current++;
    return addrs->current;
}

void printUsage(char *arg) {
   fprintf(stderr, "Usage: %s <port> [begin_ip_addr] [end_ip_addr]\n", arg); 
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printUsage(argv[0]);
        return -1;
    }

    uint16_t port = atoi(argv[1]);

    in_addr_t current = inet_addr("0.0.0.0");
    // set default ending ip to the last ip before multicast addresses
    in_addr_t ending = inet_addr("223.255.254.255");
    if (argc > 2) {
        current = inet_addr(argv[2]);
        if (argc > 3) {ending = inet_addr(argv[3]);}
        if (current == INADDR_NONE || ending == INADDR_NONE || ending < current) {
            printUsage(argv[0]);
            return -1;
        }
    }

    IPAddrs addrs = {current, ending, port};
    printf("Start: %d\nEnd: %d\nPort: %d\n", addrs.current, addrs.ending, addrs.port);
}