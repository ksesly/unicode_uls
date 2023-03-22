#include "../inc/uls.h"

void mx_print_file_access(struct stat file_statistics){

    // permission for directories
    mx_printstr(S_ISDIR(file_statistics.st_mode) ? "d" : "-");

    // permission for ?
    mx_printstr((file_statistics.st_mode & S_IRUSR) ? "r" : "-");
    mx_printstr((file_statistics.st_mode & S_IWUSR) ? "w" : "-");
    mx_printstr((file_statistics.st_mode & S_IXUSR) ? "x" : "-");

    // permission for group
    mx_printstr((file_statistics.st_mode & S_IRGRP) ? "r" : "-");
    mx_printstr((file_statistics.st_mode & S_IWGRP) ? "w" : "-");
    mx_printstr((file_statistics.st_mode & S_IXGRP) ? "x" : "-");

    // permission for pther users
    mx_printstr((file_statistics.st_mode & S_IROTH) ? "r" : "-");
    mx_printstr((file_statistics.st_mode & S_IWOTH) ? "w" : "-");
    mx_printstr((file_statistics.st_mode & S_IXOTH) ? "x" : "-");
}
