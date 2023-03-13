#include "../inc/libmx.h"

char *mx_memchr(const void *s, int c, size_t n) {
 char *temp = (char *)s;
	for (int i = 0; i < (int)n; i++) {
		if (*temp == c)
			return temp;
		temp++;
	}
	return NULL;
}


