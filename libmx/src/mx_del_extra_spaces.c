#include "../inc/libmx.h"


char *mx_del_extra_spaces(const char *str) {
    if (str == NULL)
        return NULL;
    char *first_part = mx_strtrim(str); 
    int counter = 0;
    for ( int i = 0; first_part[i] != 0; i++) {
        if (mx_isspace(first_part[i]) && mx_isspace(first_part[i - 1]))       
            counter++;
    }
    int len = mx_strlen(str);
    char *second_part = mx_strnew(len - counter);
    counter = 0;
    for ( int i = 0; first_part[i] != 0; i++) {
        if (!mx_isspace(first_part[i]) ||
             (mx_isspace(first_part[i]) && !mx_isspace(first_part[i-1])) ){
            second_part[counter] = first_part[i];
            counter++;                
        }
    }
    mx_strdel(&first_part);
    return second_part;   
}

// int main (void) {
//     char name[] = "\f   My name... is\r Neo  \t\n";
//     char *name1 =  mx_del_extra_spaces(name);
//     printf("%s", name1);
    
//     return 0;
// }


