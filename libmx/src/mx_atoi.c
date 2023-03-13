#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int result = 0;	
	int range = 1;
	for (int i = 0; str[i] != '\0'; i++) {
    		if (mx_isdigit(str[i])) 
    			result = result * 10 + str[i] - 48;
    		else if (!mx_isdigit(str[i+1]) && str[i+1] != 0)
    		    return 0;
    		//else if (mx_isspace(str[i])) 
    		//	continue;
    		else if (str[0] == '-') {
                range -= 1;
                continue;
            }
            else if (str[i] == '+')
                continue;
    		else 
    			break;
    }
 	return range * result;
}

