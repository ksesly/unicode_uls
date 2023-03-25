#include "../inc/uls.h"


t_list *mx_dir_man(char* direct) {
    DIR *dir = opendir(direct);
    if (!dir) {
        mx_uncreated_file(direct); 
    }
    t_list *spisok = mx_return_spisok(dir);
    closedir(dir);
    return spisok;
}

void mx_full_ls_function(char* argv[], int argc) {
    if (argc == 1){
        t_list *spisok = mx_dir_man(".");
        mx_ls(spisok);
    }
    else if (mx_strcmp(argv[1], "-G") == 0){
        mx_check_G(argc, argv);
    }
    else if (mx_strcmp(argv[1], "-l") == 0){
        mx_check_l(argc, argv);
    }
    else if (mx_strcmp(argv[1], "-1") == 0){
        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); 
        }
        t_list *spisok = mx_return_spisok(dir);
        //mx_bubble_list_sort(spisok);
        mx_print_row(spisok);
        closedir(dir);
    }
    else if (mx_strcmp(argv[1], "-C") == 0){
        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); 
        }
        t_list *spisok = mx_return_spisok(dir);
        //mx_bubble_list_sort(spisok);
        mx_print_column(spisok);
        closedir(dir);
    }
    else if (mx_strcmp(argv[1], "-a") == 0){
        mx_check_a();
    }
    else if (mx_strcmp(argv[1], "-A") == 0){
        mx_check_A();
    }
    else if (mx_strcmp(argv[1], "-l") != 0){
        t_list *file_spisok = mx_list_file(argc, argv, 1);
        t_list *dir_spisok = mx_list_dir(argc, argv, 1);
        while (file_spisok != NULL){
            mx_printstr(file_spisok->data);
            mx_printstr("  ");
            file_spisok = file_spisok->next;
        }
        mx_printchar('\n');
        while (dir_spisok != NULL){
            mx_printchar('\n');
            t_list  *sp = mx_dir_man(dir_spisok->data);
            //DIR *dir = opendir(dir_spisok->data);

            mx_printstr(dir_spisok->data);
            mx_printstr(":\n");
            //t_list *sp = mx_return_spisok(dir);
            mx_no_flags(sp);
            mx_printchar('\n');
            //closedir(dir);
            dir_spisok = dir_spisok->next;
        }
    }
}



