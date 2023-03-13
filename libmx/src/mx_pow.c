#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    if (n == 0)	
    	return 0;
    if (n > 0) {
        if (pow == 0) return 1; 
        if (pow > 0) {
            double temp = n;
            for (int i = 1; i < (int)pow; i++) 
                n = n * temp;
        }
        else return 0;
    }
    return n;
}

// int main(void) {
//     printf("%f", mx_pow(3, 2));
// }


