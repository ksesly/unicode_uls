#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return -2;
    char *temp = mx_strstr(str, sub);
    if (temp == NULL) 
        return -1;
    return temp - str;
}

// int main(void) {
//     printf("%i\n", mx_get_substr_index("McDonalds", "Don"));
//     printf("%i\n",mx_get_substr_index("McDonalds Donuta", "on"));
//     printf("%i\n",mx_get_substr_index("McDonalds", "Donatello"));
//     printf("%i\n",mx_get_substr_index("McDonalds", NULL));
//     printf("%i\n",mx_get_substr_index(NULL, "Don"));

// }




