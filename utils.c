#include "utils.h"

char *lfgets(char *restrict s, int n, FILE *restrict stream, size_t limit) {
    char *res = fgets(s, n, stream);
    if (!res) return NULL;

    size_t size = strlen(s);
    if (size < limit) {
        fprintf(stderr, "Address not read from standard input, defaulting to 0.0.0.0\n");
        return NULL;
    }
    size--;
    char *p = s + size;
    // this probs wont ever be run on windows
    // but add the check for a newline just in case
    if (*p == '\n' || *p == '\r') {
        *p = 0;
    }

    return s;
}

ssize_t lread(fd_t fd, void *buf, size_t nbytes, in_addr_t ip) {
    int num_read = read(fd, (char *)buf, nbytes - 1);
    if (num_read < 2) {
        printf("0x%x\n", ip);
    } else {
        num_read--;
        uint8_t *p = (uint8_t *)buf + num_read;
        if (*p == '\n' || *p == '\r') {
            *p = 0;
        }
        printf("0x%x: %s\n", ip, (char *)buf);
    }
    return num_read;
}