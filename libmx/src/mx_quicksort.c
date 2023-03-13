#include "../inc/libmx.h"

void swap (char **s1, char **s2) {
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int mx_quicksort(char **arr, int left, int right) {
    int swap_counter = 0;
    if (arr == NULL) 
        return -1;
    int middle = (right + left) / 2;
    char *pivot = arr[middle];
    int j = right;
    int i = left;
    while ( i <= j) { 
        if(mx_strlen(arr[i]) < mx_strlen(pivot))  
            i++;
        if(mx_strlen(arr[j]) > mx_strlen(pivot)) 
            j--;
        if ((i <= j) && (mx_strlen(arr[i])) != (mx_strlen(arr[j]))) {
            swap(&arr[i], &arr[j]);
            swap_counter++;
        }         
        i++;
        j--;
    }
    if(left < j)
        swap_counter += mx_quicksort(arr, left, j);
    if(i < right)
        swap_counter += mx_quicksort(arr, i, right);
    return swap_counter;
}

// int main (void) {
//     // char *array[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
//     // printf("%i\n", mx_quicksort(array, 0 , 3));
//     // for (int i = 0; array[i] != 0; i++) {
//     //     printf("%s ", array[i]);
//     // }
//     char *array1[] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Biff Tannet"};
//     printf("%i\n", mx_quicksort(array1, 0 , 5));
//     for (int i = 0; array1[i] != 0; i++) {
//         printf("%s ", array1[i]);
//     }

// }

