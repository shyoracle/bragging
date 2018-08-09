/**
 * Fowler–Noll–Vo hash function
 * Reference: https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
 * */
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "hashutil.h"

#define FNV_PRIME32 16777619
#define FNV_PRIME64 1099511628211

static int fnv1(const char *bytes, size_t dlen, int64_t fnv_offset) {
    int64_t hash = fnv_offset;

    for (size_t i = 0; i < dlen; ++i) {
        hash *= FNV_PRIME32;
        hash ^= bytes[i];
    }
    return (int)hash;
}

static int fnv1a(const char *bytes, size_t dlen, int64_t fnv_offset) {
    int64_t hash = fnv_offset;

    for (size_t i = 0; i < dlen; ++i) {
        hash ^= bytes[i];
        hash *= FNV_PRIME32;
    }
    return (int)hash;
}

static int fnv0(const char *bytes, size_t dlen) {
    return fnv1(bytes, dlen, 0);
}

int fnv(const void *data, size_t dlen, int fnv_offset, FNV_Type fnv_type) {
    switch (fnv_type) {
        case FNV_1:
            return fnv1((const uint8_t *)data, dlen, fnv_offset);
        case FNV_1a:
            return fnv1a((const uint8_t *)data, dlen, fnv_offset);
        case FNV_0:
            return fnv0((const uint8_t *)data, dlen);
        default:
            return 0;
    }
}
