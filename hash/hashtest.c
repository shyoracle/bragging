/**
 * Fowler–Noll–Vo hash function
 * Reference: https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
 * */
#include <stdio.h>
#include <string.h>
#include "hashutil.h"

int main(void) {
    const char *data = "hello world, this isn't fun at all";
    printf("%s -- %d\n", data, fnv(data, strlen(data), 0, FNV_0));
    printf("%s -- %d\n", data, fnv(data, strlen(data), 0, FNV_1));
    printf("%s -- %d\n", data, fnv(data, strlen(data), 100, FNV_1a));
}
