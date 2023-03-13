#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    int length = mx_strlen(str);
    char *temp_arr = mx_strnew(length);
    temp_arr = mx_strcpy(temp_arr, str);
    return temp_arr;
}


// int main(void) {
//     char *arr = "Hello";
//     char *arr2 = mx_strdup(arr);
//     printf("%s", arr2);
//     free(arr2);
// }



