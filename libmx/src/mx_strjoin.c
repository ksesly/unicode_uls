#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s2 == NULL)
        return (char *)s1;
    if (s1 == NULL)
        return (char *)s2;
    char *temp = mx_strnew(*s1 + *s2);
    int let = 0;
    temp = mx_strdup(s1);
    mx_strcat(temp, s2);
    while (temp[let]) 
        let++;
    temp[let] = '\0';
    return temp;
}


/*int main (void) {
    char s1[] = "hello";
    //char s2[] = "world";
    char *s3 = NULL;
    printf("%s", mx_strjoin(s3, s1));
    return 0;
}*/


