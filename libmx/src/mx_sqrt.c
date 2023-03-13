#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x >= 2147483647)
        return 0;
    if (x > 0) {
        for (int i = 1; i <= x; i++) {
            if (x / i == i) 
                return i;
        }
    }
    return 0;
}

// int main(void) {
//     printf("%i", mx_sqrt(64));
// }

