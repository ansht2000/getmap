#include "getmap.h"
#include "utils.h"

in_addr_t current;
in_addr_t ending;

in_addr_t generate() {
    // buffer to hold input id address
    uint8_t buf[16];

    if (!current && !ending) {
        size_t buf_len = arrlen(buf);
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

uint8_t *header(fd_t s, in_addr_t ip) {
    static uint8_t buf[256];
    size_t buf_len = arrlen(buf);
    memset(buf, 0, buf_len);
    lread(s, (char *)buf, buf_len - 1, ip);
    return buf;
}

bool tcpConnect(in_addr_t ip, uint16_t port) {
    struct sockaddr_in sock;
    fd_t s = socket(AF_INET, SOCK_STREAM, 0);
    assert(s > 0);
    sock.sin_family = AF_INET;
    sock.sin_port = htons((int)port);
    sock.sin_addr.s_addr = ip;

    int ret = connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr));
    if (ret) {
        close(s);
        return false;
    } else {
        header(s, ip);
        close(s);
        return true;
    }

    return false;
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

    in_addr_t ip;
    while ((ip = generate())) {
        tcpConnect(ip, port);
    }

    return 0;
}