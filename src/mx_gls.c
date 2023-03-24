#include "../inc/uls.h"

void mx_gls(int argc, char* argv[]) {

    t_list *file_spisok = NULL;
    t_list *dir_spisok = NULL;
    struct stat file_statistics;

	


    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &file_statistics) == 0){
            if (S_ISDIR(file_statistics.st_mode)) {
                mx_push_back(&dir_spisok, argv[i]);
            }
            else {
                mx_push_front(&file_spisok, argv[i]);
            }
        }
        else {
            mx_uncreated_file(argv[i]);
        }
    }
	mx_bubble_list_sort(file_spisok);
    mx_bubble_list_sort(dir_spisok);
	

    // while (file_spisok != NULL){
    //     if (S_ISREG(file_statistics.st_mode)) {
    //         write(STDOUT_FILENO, red_col, 5);
    //         write(STDOUT_FILENO, file_spisok->data, mx_strlen(file_spisok->data));
    //         write(STDOUT_FILENO, reset_col, 4);
    //         mx_printstr("  "); 
    //     }
    //     file_spisok = file_spisok->next;
    // }
    mx_print_G(file_spisok, file_statistics);
    mx_printchar('\n');
    while (dir_spisok != NULL){
            mx_printchar('\n');
            
            DIR *dir = opendir(dir_spisok->data);

            mx_printstr(dir_spisok->data);
            mx_printstr(":\n");
            t_list *sp = mx_return_spisok(dir);
            mx_print_G(sp, file_statistics);
            mx_printchar('\n');
            closedir(dir);
            dir_spisok = dir_spisok->next;
        }
    
}

void mx_print_G(t_list *spisok, struct stat file_statistics) {

    const char* blue_col = "\033[34m"; //blue
    const char* red_col = "\033[31m"; //red
    const char* reset_col = "\033[0m"; //standart
    const char* yell_col = "\033[33m"; // yellow
    const char* mag_col = "\033[35m"; // magenta

    for (t_list *i = spisok; i != NULL; i = i->next) {
        if (stat(i->data, &file_statistics) == 0){
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
            else if (S_ISSOCK(file_statistics.st_mode)) {
                write(STDOUT_FILENO, mag_col, 5);
                write(STDOUT_FILENO, i->data, mx_strlen(i->data));
                write(STDOUT_FILENO, reset_col, 4);
                mx_printstr("  "); 
            }
            else {
                mx_printstr(i->data);
                mx_printstr("  "); 
            }
        }
    }
    mx_printchar('\n');
}

