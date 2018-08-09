#ifndef __HASHUTIL_H__
#define __HASHUTIL_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    FNV_1,
    FNV_1a,
    FNV_0
} FNV_Type;

int fnv(const void *bytes, size_t dlen, int fnv_offset, FNV_Type fnv_type);

#ifdef __cplusplus
}
#endif

#endif
