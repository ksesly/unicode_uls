#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (sub == NULL || str == NULL) 
        return -1;
    if (sub == 0)
        return 0;
    int len = mx_strlen(str);
    int len_sub = mx_strlen(sub);
    int counter_substr = 0;
    while (*str) {
        if (len >= len_sub) 
            if (mx_strncmp(str, sub, len_sub) == 0) 
                counter_substr++;
        str++;
    }
    return counter_substr;
}


// int main(void) {
//     char *str = "yo, yo, yo, Neo";
//     char *sub = "yo";
//     printf("%i\n", mx_count_substr(str, sub));
//     printf("%i\n", mx_count_substr(str, NULL));
//     printf("%i\n", mx_count_substr(NULL, sub));
//     return 0;
// }


