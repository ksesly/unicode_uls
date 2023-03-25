#include "../inc/uls.h"

void mx_print_dir_G(t_list *dir_spisok) {
    while (dir_spisok != NULL){
            mx_printchar('\n');
            
            DIR *dir = opendir(dir_spisok->data);

            mx_printstr(dir_spisok->data);
            mx_printstr(":\n");
            t_list *sp = mx_return_spisok(dir);
            mx_bubble_list_sort(sp);
            mx_print_G(sp, dir_spisok->data);
            mx_printchar('\n');
            closedir(dir);
            dir_spisok = dir_spisok->next;
        }
    
}

void mx_print_G(t_list *spisok, char *dir) {
    struct stat file_statistics;
    const char* blue_col = "\033[34m"; //blue
    const char* red_col = "\033[31m"; //red
    const char* reset_col = "\033[0m"; //standart
    const char* yell_col = "\033[33m"; // yellow
    //const char* mag_col = "\033[35m"; // magenta

    for (t_list *i = spisok; i != NULL; i = i->next) {
        char *buff = mx_strdup(dir);
        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);
        printf("%s ", buff);
        
        if (stat(buff, &file_statistics) == 0){
            if (mx_strcmp(i->data, "Makefile") == 0) {
                mx_printstr(i->data);
                mx_printstr("  "); 
            }
            else if(S_ISDIR(file_statistics.st_mode)) {
                write(STDOUT_FILENO, blue_col, 5);
                write(STDOUT_FILENO, i->data, mx_strlen(i->data));
                write(STDOUT_FILENO, reset_col, 4);
                mx_printstr("  "); 
            }
            else if (S_ISREG(file_statistics.st_mode)) {
                write(STDOUT_FILENO, red_col, 5);
                write(STDOUT_FILENO, i->data, mx_strlen(i->data));
                write(STDOUT_FILENO, reset_col, 4);
                mx_printstr("  "); 
            }
            else if (S_ISBLK(file_statistics.st_mode) || S_ISCHR(file_statistics.st_mode)) {
                write(STDOUT_FILENO, yell_col, 5);
                write(STDOUT_FILENO, i->data, mx_strlen(i->data));
                write(STDOUT_FILENO, reset_col, 4);
                mx_printstr("  "); 
            }
            else if (S_ISFIFO(file_statistics.st_mode)) {
                write(STDOUT_FILENO, yell_col, 5);
                write(STDOUT_FILENO, i->data, mx_strlen(i->data));
                write(STDOUT_FILENO, reset_col, 4);
                mx_printstr("  "); 
            }
            // else if (S_ISSOCK(file_statistics.st_mode)) {
            //     write(STDOUT_FILENO, mag_col, 5);
            //     write(STDOUT_FILENO, i->data, mx_strlen(i->data));
            //     write(STDOUT_FILENO, reset_col, 4);
            //     mx_printstr("  "); 
            // }
            else {
                mx_printstr(i->data);
                mx_printstr("  "); 
            }
        }
    }
    mx_printchar('\n');
}

