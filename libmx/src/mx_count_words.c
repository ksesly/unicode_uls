#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimeter) {
	int counter = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if(str[i] == delimeter) {
			if (str[i + 1] != delimeter && str[i + 1] != '\0') {
				counter++;
			}
		}
	}
	return counter;
}


