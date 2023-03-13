#include "../inc/libmx.h"

// read from given fd into the lineptr until it:
// reaches a delim character (delim is not returned)
// reaches end of the file (eof)

//a line is a sequence of characters befor the delimeter!

/*
- works correctly with any fd includings
- works correctly with any positive integer buf_size. buf_size must be
- passed to the function read as a parameter nbytes 
- can read all data from the given fd until the  EOF, one line pre call
- may content a single static variable while global variables are still forbidden
- may have undefined behavior while reading from the binary file
*/

//return 
// the number of bytes that are written into lineptr
//-1 if EOF is reached and there is nothing to write in lineptr
// -2 in case of errors or fd is invalid

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    //int file = open(fd, O_RDONLY);
    if (!fd ) {
        close(fd);
        return -2;
    }
    int number_of_bytes = 0;
    int element = 0;
    char *buf = NULL;
    //char *temp = mx_strnew(buf_size);
    while (buf == NULL || buf[element] != delim) {
        if (buf == NULL || *buf == '\0' ) {
            buf = mx_strnew(buf_size);
            if(!read(fd, buf, buf_size))
                return number_of_bytes;
        }
        if (buf[element] != delim)
            (*lineptr)[number_of_bytes++] = buf[element++];
        else
            break;
        if (buf[element] == '\0') {
            element = 0;
            mx_strdel(&buf);
        }
    }
    char *result = mx_strdup(&buf[element+1]);
    mx_strcpy(buf, result);
    mx_strdel(&result);
    return 0;
}


// int main(void) {
//     char *str;
//     int fd = open("fragment", O_RDONLY);
//     int res = mx_readline(&str, 7, '\n', fd);
//     //int res = mx_readline(&str, 35, 'a', fd);
//     printf("%i", res);
//     printf("%s", res);
// }


