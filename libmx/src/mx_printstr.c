#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    int length = mx_strlen(s);
    for (int i = 0; i < length; i++) {
        write(1, &s[i], 1);
    }
}

// int main(void) {
//     char *s = "Hello";
//     mx_printstr(s);
// }


