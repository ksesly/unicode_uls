#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    
    int temp = open(file, O_RDONLY);
    if (temp == -1) {
        return NULL; 
    }
    int size = 0;
    char buf;
    while (read(temp, &buf, 1)) 
        size++;
    if (!size)
        return NULL;
    close(temp);
    temp = open(file, O_RDONLY);
    if (temp == -1) {
        return NULL; 
    }
    char *temp_word = mx_strnew(size);
    if (!temp_word) 
        return NULL;
    read(temp, temp_word, size);
    return temp_word;
}


// int main (int argc, char *argv[]) {
//     if (argc == 1)
//         return 1;
//     printf("%s", mx_file_to_str(argv[1]));
//     //printf("%i", mx_strlen(mx_file_to_str(argv[1])));
//     return 0;
// }


