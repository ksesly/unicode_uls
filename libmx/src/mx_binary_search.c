#include "../inc/libmx.h"

//int mx_strcmp(const char *s1, const char *s2);

//function search for the string in array  with the given size
//use binary search algorithm (input is already sorted)

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int first_part = 0;
	int second_part = size - 1;
	int middle_line;
	while (second_part >= first_part){
		middle_line = (first_part + second_part) / 2;
		if (mx_strcmp(s, arr[middle_line] ) > 0) {
			first_part = middle_line + 1;
			(*count)++;
		} else if(mx_strcmp(s, arr[middle_line]) < 0) {
			second_part = middle_line - 1;
			(*count)++;
		} else {
		    (*count)++;
			return middle_line;
		}	
	}
	*count = 0;
	return -1; 		
}

// int main (void) {
// 	char *arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
// 	int count = 0;
// 	printf("%i ", mx_binary_search(arr, 6, "aBz", &count));
// 	printf("%i", count);
// } 


