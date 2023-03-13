#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2);

//sorts an array of strings in place in lexicographical order
//use the bubble sort algorithm

int mx_bubble_sort(char **arr, int size) {
	int sort_counter = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mx_strcmp(arr[j], arr[j+1]) > 0) {
				sort_counter++;
				char *temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
    //only for checking the rigth order of the sorting
    //don`t touch these hashes!
	//for (int k = 0; k < size; k++) 
	//    printf("%s\n", arr[k]);
	return sort_counter;
}

// int main (void) {
// 	char *arr[] = {"abc", "xyz", "ghi", "def"};
// 	printf("%d", mx_bubble_sort(arr, 4));
// }



