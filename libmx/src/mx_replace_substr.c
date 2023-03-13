#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    //check for null 
    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
    int counter = mx_count_substr(str, sub);
    //if there are no equals in string with delim
    if (counter == 0) {
        char *s1 = mx_strnew(mx_strlen(str));
        mx_strcpy(s1, str);
        return s1;
    }
    int size = mx_strlen(str) - mx_strlen(sub) + mx_strlen(replace) * counter;
    char *temp = mx_strnew(size);
    //char *temp_res = temp;
    //char *sub_temp = mx_strstr(str, sub);
    int equels = 0;
    while (equels < size && *str != 0) {
        int position = mx_get_substr_index(str, sub);
        if (position == 0) {
            int i = 0; 
            while (i < mx_strlen(replace)) {
                temp[equels] = replace[i];
                equels++;
                i++;
            }
            str += mx_strlen(sub);
            continue;
        }
        temp[equels] = *str;
        str++;
        equels++;
    }
    return temp;
}

// int main (void) {
//     printf("%s\n", mx_replace_substr("McDonalds", "alds", "uts"));
//     printf("%s\n", mx_replace_substr("Ururu turu", "ru", "ta"));
//     return 0;
// }


