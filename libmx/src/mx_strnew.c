#include "../inc/libmx.h"

//create new alocating-memmory space for a new string

char *mx_strnew(const int size) {
    if (size < 0)
        return NULL;
    char *new_string = (char*)malloc(sizeof(char) * size + 1);
    int i = 0;
    for (i = 0; i <= size; i++) 
        new_string[i] = '\0';
    return new_string;
}


// int main(void) {
//     char *arr = mx_strnew(0);
//     arr = "";
//     printf("%s", arr);
// }


