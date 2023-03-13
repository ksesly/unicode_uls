#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    for (int i = 0; i < (int)n; i++) 
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
    return dst;
    
}


