#include "../inc/libmx.h"

bool mx_isspace(char c) {
	if (c == 0x20 || c == 0x09 || c == 0x0a) {
		return 1;
	}        
	else if (c == 0x0b || c == 0x0c || c == 0x0d ) {
		return 1;
	}
	else {
		return 0;
	 }
}

