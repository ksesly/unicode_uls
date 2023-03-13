#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	char rev_hex[128];
	int size = 0;
	while(nbr > 0) {
		unsigned long temp = nbr % 16;
		if (temp >= 10)
			rev_hex[size] = (char)(temp + 87);
		else
			rev_hex[size] = (char)(temp + 48);
		size++;
		nbr /= 16;
	}
	char *hex = mx_strnew(size);
	for (int i = 0; i < size; ++i)
		hex[i] = rev_hex[size - i - 1];
	return hex;
}


