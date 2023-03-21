#include "../inc/uls.h"

void mx_print_file_access(struct stat file_stat){

    mx_printstr(S_ISDIR(file_stat.st_mode) ? "d" : "-");

    mx_printstr((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    mx_printstr((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    mx_printstr((file_stat.st_mode & S_IXUSR) ? "x" : "-");

    // определяем разрешения для группы
    mx_printstr((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    mx_printstr((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    mx_printstr((file_stat.st_mode & S_IXGRP) ? "x" : "-");

    // определяем разрешения для остальных пользователей
    mx_printstr((file_stat.st_mode & S_IROTH) ? "r" : "-");
    mx_printstr((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    mx_printstr((file_stat.st_mode & S_IXOTH) ? "x" : "-");
}
