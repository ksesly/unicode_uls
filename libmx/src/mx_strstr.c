#include "../inc/libmx.h"


//haystack - the string to be scanned
//needle - small string that is need to be search

char *mx_strstr(const char *haystack, const char *needle) {
    //if (haystack == NULL || needle == NULL)
    //    return NULL;
    int len = mx_strlen(needle);
    if (len == 0)
        return (char *)haystack;
    haystack = mx_strchr(haystack, *needle);
    while (haystack != 0) {
        if (mx_strncmp(haystack, needle, len) == 0)
            return (char *)haystack;
        haystack = mx_strchr(haystack + 1, *needle);
    }
    return NULL;
}

// int main (void) {
//     char *haystack = "HelloWorld";
//     char *needle = "World";
//     printf("%s\n", mx_strstr(haystack, needle));
//     return 0;
// }


