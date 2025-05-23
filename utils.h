#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// DOES NOT WORK FOR ARRAYS PASSED TO A FUNCTION
#define len(x) (sizeof(x) / sizeof((x)[0]))

// get a string from fgets without the newline
char *lfgets(char *restrict s, int n, FILE *restrict stream, size_t limit);


#endif