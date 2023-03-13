#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    for (int i = 0; i <= *src; i++) {
    dst[i]=src[i];
        if (dst[i] == dst[len-1]) {
            return (char *)dst;
        }
    }
    return 0;
}


