#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {

    size_t length = mx_strlen(s1);

    if (n < length) {
        length = n;
    }

    char *duplicate = mx_strnew(length);
    mx_strncpy(duplicate, s1, length);
    
    return duplicate;
}
// int main(void) {
//     char *arr = "Hello";
//     char *arr2 = mx_strndup(arr, 5);
//     printf("%s", arr2);
//     free(arr2);
// }


