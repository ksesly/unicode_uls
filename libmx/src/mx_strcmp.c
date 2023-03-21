#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    while (1) {
        if (*s1 == 0 && *s2 == 0)
            return 0;
        if (/*mx_tolower*/(*s1) != /*mx_tolower*/(*s2))
            break;
        s1++;
        s2++;
    }
    return (/*mx_tolower*/(*s1) - /*mx_tolower*/(*s2));
}

// int main(void) {
//     char word1[] = "abCd";
//     char word2[] = "abcd";
//     printf("%i", mx_strcmp(word1, word2));
// }


