#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *temp;
    if (size == 0) {
        free(ptr);
        ptr = NULL;
        return NULL;
    }
    if (ptr == NULL) 
        temp = malloc(size);
    else {
        if (malloc_size(ptr) < size) {
            temp = malloc(size);
            mx_memcpy(temp, ptr, malloc_size(ptr));
            free(ptr);
        }
        else
            temp = ptr;
    }
    return temp;
    if (size > 0)
        return ptr;
    return NULL;
}



