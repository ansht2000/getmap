#include "getmap.h"
#include "utils.h"

in_addr_t current;
in_addr_t ending;

in_addr_t generate() {
    // buffer to hold input id address
    uint8_t buf[16];

    if (!current && !ending) {
        size_t buf_len = len(buf);
        memset(buf, 0, buf_len);
        if (!lfgets((char *)buf, buf_len, stdin, 7)) {
            return (in_addr_t)(0);
        }
        return inet_addr((char *)buf);
    }

    if (current >= ending) {
        return (in_addr_t)0;
    }
    current++;
    return current;
}

void printUsage(char *arg) {
   fprintf(stderr, "Usage: %s <port> [begin_ip_addr] [end_ip_addr]\n", arg); 
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printUsage(argv[0]);
        return -1;
    }

    uint16_t port = (uint16_t)atoi(argv[1]);

    if (argc > 2) {
        current = inet_addr(argv[2]);
        ending = inet_addr("223.255.254.255");
        if (argc > 3) {ending = inet_addr(argv[3]);}
        if (current == INADDR_NONE || ending == INADDR_NONE || ending < current) {
            printUsage(argv[0]);
            return -1;
        }
    }

    // printf("Start: %d\nEnd: %d\nPort: %d\n", addrs.current, addrs.ending, addrs.port);
    in_addr_t temp = generate();
    printf("0x%x\n", temp);
    temp = generate();
    printf("0x%x\n", temp);
}