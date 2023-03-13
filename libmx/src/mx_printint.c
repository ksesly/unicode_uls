#include "../inc/libmx.h"

void mx_printint(int n) {
    int digit = 0;
    int result[128];
    if (n < 0) {
        n *= -1;
        mx_printchar('-');
    }
    if (n == 0) {
        mx_printchar('0');
        return;
    }  
    else if (n == -2147483648)
        write(1, "2147483648", 11);
    else {
        while (n > 0) {
            result[digit] = n % 10;
            n = n / 10;
            digit++; 
        } 
    }
    for (int i = digit - 1; i >= 0; i--) {
        int number = result[i] + '0';
        mx_printchar(number);
    }
}

// int main (void) {
//     int my_number = -2147483648;
//     mx_printint(my_number);
//     mx_printchar('\n');
// }


