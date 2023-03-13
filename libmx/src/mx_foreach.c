#include "../inc/libmx.h"

// void mx_printchar(char c) {
//     write(1, &c, 1);
// }

// void mx_printint(int n) {
//     int digit = 0;
//     int result[128];
//     if (n < 0) {
//         n *= -1;
//         mx_printchar('-');
//     }
//     if (n == 0) {
//         mx_printchar('0');
//         return;
//     }  
//     else {
//         while (n > 0) {
//             result[digit] = n % 10;
//             n = n / 10;
//             digit++; 
//         } 
//     }
//     for (int i = digit - 1; i >= 0; i--) {
//         int number = result[i] + '0';
//         mx_printchar(number);
//     }
// }


void mx_foreach(int *arr, int size, void (*f)(int)) {
    for (int i = 0; i < size; i++) 
        f(arr[i]);
}

// int main(void) {
//     int arr[] = {1, 2, 3, 4, 5};
//     mx_foreach(arr, 5, mx_printint);
// }

