#include "../inc/uls.h"

void mx_print_file_access(struct stat file_statistics) {

    // permission for directories
    if (S_ISDIR(file_statistics.st_mode)) {
        mx_printchar('d'); 
    }
    else if (S_ISLNK(file_statistics.st_mode)) {
        mx_printchar('l'); 
    }
    else if (S_ISCHR(file_statistics.st_mode)) {
        mx_printchar('c'); 
    }
    else if (S_ISSOCK(file_statistics.st_mode)) {
        mx_printchar('s'); 
    }
    else if (S_ISBLK(file_statistics.st_mode)) {
        mx_printchar('b'); 
    }
    else 
        mx_printchar('-');

    


    mx_printstr((file_statistics.st_mode & S_IRUSR) ? "r" : "-");
    mx_printstr((file_statistics.st_mode & S_IWUSR) ? "w" : "-");
    mx_printstr((file_statistics.st_mode & S_IXUSR) ? "x" : "-");


    mx_printstr((file_statistics.st_mode & S_IRGRP) ? "r" : "-");
    mx_printstr((file_statistics.st_mode & S_IWGRP) ? "w" : "-");
    mx_printstr((file_statistics.st_mode & S_IXGRP) ? "x" : "-");


    mx_printstr((file_statistics.st_mode & S_IROTH) ? "r" : "-");
    mx_printstr((file_statistics.st_mode & S_IWOTH) ? "w" : "-");

    if (S_ISVTX & file_statistics.st_mode) {
        mx_printchar('t');
    }
    else if (S_IXOTH & file_statistics.st_mode) {
        mx_printchar('x');
    }
    else {
        mx_printchar('-');
    }
    
}
