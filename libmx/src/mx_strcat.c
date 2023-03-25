#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    char *p = s1;
    
    while (*p != '\0') { // находим конец s1
        p++;
    }
    
    while (*s2 != '\0') { // копируем символы из s2 в конец s1
        *p++ = *s2++;
    }
    
    *p = '\0'; // добавляем нулевой символ в конец
    
    return s1;
}

