#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 && s2){
        int l1 = mx_strlen(s1);
        int l2 = mx_strlen(s2);
        char *arr = mx_strnew(l1 + l2);
        arr = mx_strdup(s1);
        arr = mx_strcat(arr, s2);
        return arr;
    }
    else if(s1) return mx_strdup(s1);
    else if(s2) return mx_strdup(s2);
    else return NULL;
}


/*int main (void) {
    char s1[] = "hello";
    //char s2[] = "world";
    char *s3 = NULL;
    printf("%s", mx_strjoin(s3, s1));
    return 0;
}*/


