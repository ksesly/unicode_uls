#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int length = 0;
    for (int i = 0; s[i] != 0; i++) {
        length++; 
    }
    return length;
}

double mx_pow(double n, unsigned int pow) {
    if (n > 0) {
        if (pow == 0) return 1; 
        if (pow > 0) {
            double temp = n;
            for (int i = 1; i < (int)pow; i++) 
                n = n * temp;
        }
        else return 0;
    }
    else return 0;
    return n;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long number = 0;
    int length = mx_strlen(hex);
    int power = 0;
    for (int i = length - 1; hex[i] != 0; i--) {
            if (hex[i] >= 'A' && hex[i] <= 'F') 
                number += (hex[i] - 55) * mx_pow(16, power);
            else if (hex[i] >= '0' && hex[i] <= '9')
                number += (hex[i] - 48) * mx_pow(16, power);
            else if (hex[i] >= 'a' && hex[i] <= 'f') 
                number += (hex[i] - 87) * mx_pow(16, power);
            power++;
    }
    return number;
}

// int main (void) {
//     printf("%lu", mx_hex_to_nbr("ffffffffffff"));
// }

