#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int i = 0;
    int c = 0;
    for ( i = 0; i < mx_strlen(s1); i++) {
        if (s1[i] == '\0') {
            continue;
        }
    }
    for ( c = 0; c < mx_strlen(s2); c++) {
        s1[i + c] = s2[c];
    }
    s1[i + c] = '\0';
    return (char *)s1;
    return 0;
}

