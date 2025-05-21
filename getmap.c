#include "getmap.h"

in_addr_t generate(IPAddrs *addrs) {
    if (addrs->current >= addrs->ending) {
        return (in_addr_t)0;
    }
    addrs->current++;
    return addrs->current;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr,
                "Usage: %s <port> [begin_ip_addr] [end_ip_addr]\n",
                argv[0]);
        return -1;
    }
}