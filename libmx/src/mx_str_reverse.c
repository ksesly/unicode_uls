#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
        int c = 0;
        while (s[c] != 0) {
                c++;
        }
        for (int i = 0; i <= (c / 2); i++) {
                mx_swap_char(&s[i], &s[c - i - 1]);
        }
}


