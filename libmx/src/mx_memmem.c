#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (little_len == 0)
        return 0;
    void *temp;
    temp = mx_memchr(big, *(unsigned char*)little, big_len);
    while (temp != NULL) {
        size_t last = big_len - ((unsigned char *)temp - (unsigned char *) big);
        if (mx_memcmp(temp, little, little_len) == 0)
            return temp;
        if (last < little_len) 
            break;
        temp = mx_memchr((unsigned char *)temp + 1, *(unsigned char *)little, big_len);
    }
    return NULL;
}



