#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)  {
    for (int i = 0; i < (int)n; i++) {
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        if (((unsigned char *)src)[i] == (unsigned char)c)
            return (void *)&((unsigned char *)src)[i+1];
    }
    return dst;
}


