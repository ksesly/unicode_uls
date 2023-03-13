#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL)
        return NULL;
    int len = mx_strlen(str);
    char *temp = mx_strnew(len);
    int let = 0;
    int counter = 0;
    for (let = 0; str[let] != '\0'; let++) {
        if (counter != 0 && (!mx_isspace(str[let]) 
                   || !mx_isspace(str[let + 1]))) {
            temp[counter] = str[let];
            counter++; 
        } if (!mx_isspace(str[let]) && counter == 0) {
            temp[counter] = str[let];
            counter++;    
         }  
         
    }
    char *array = mx_strnew(counter);
    mx_strncpy(array, temp, counter);
    mx_strdel(&temp);
    //mx_strdel(&array);
    return array;
}

/*int main (void) {
    char name[] = "\f   My name... is Neo  \t\n";
    char *name1 =  mx_strtrim(name);
    printf("%s", name1);
    
    return 0;
}*/


