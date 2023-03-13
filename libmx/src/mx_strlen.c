#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int length = 0;
    for (int i = 0; s[i] != 0; i++) {
        length++; 
    }
    return length;
}



