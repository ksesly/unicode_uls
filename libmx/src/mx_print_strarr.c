#include "../inc/libmx.h"

//output a string array with a delim between the elements
//nothing if arr or delim don`t exist
//a newline ar the and
//arr must be NULL-terminated, in other cases the behavior is undefined

void mx_print_strarr(char **arr, const char *delim) {
    if (delim == NULL || arr == NULL) 
        return;
    for (int i = 0; arr[i] != NULL; i++) {
        mx_printstr(arr[i]);
        if (arr[i + 1])
            mx_printstr(delim);
    }
    mx_printchar('\n');
}

// int main (void) {
//     char *array[] = {"i", "really", "want", "to", "return", "home.."};
//     mx_print_strarr(array, " ");
// }

