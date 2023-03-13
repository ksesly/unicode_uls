#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
	for (int i = 0; i < *s; ) {
		while (s[i] != 0 && s[i] != c) {
			i++;
		}
		if (s[i] == c) {
			return (char *)s + i;
		} else {
			return 0;
		}
	}
	return 0;
}



