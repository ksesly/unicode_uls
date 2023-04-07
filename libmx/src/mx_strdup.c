#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    // int length = mx_strlen(str);
    // char *temp_arr = mx_strnew(length);
    // temp_arr = mx_strcpy(temp_arr, str);
    // return temp_arr;
    if (str == NULL)
        return NULL;
    char *dup = (char *)malloc(sizeof(char) * (mx_strlen(str) + 1));
    if (dup == NULL)
        return NULL;
    mx_strcpy(dup, str);
    return dup;
}


// int main(void) {
//     char *arr = "Hello";
//     char *arr2 = mx_strdup(arr);
//     printf("%s", arr2);
//     free(arr2);
// }



