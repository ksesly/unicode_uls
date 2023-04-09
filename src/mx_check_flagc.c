#include "../inc/uls.h"


//ne rabotaet vse ravno


void mx_check_l(int argc, char* argv[]) {
	if (argc == 2){
        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); 
        }
        t_list *spisok = mx_return_spisok(dir);
        mx_lls(spisok, ".");
        closedir(dir);
        //return spisok;
    }
    else if (argc >= 3){
        t_list *file_list = NULL;
        t_list *dir_list = NULL;
        struct stat file_statistics;
        for (int i = 2; i < argc; i++){
            DIR *dir = opendir(".");
            if (!dir) {
                mx_uncreated_file("."); 
            }
            t_list *spisok = mx_return_spisok(dir);
            //mx_printstr("hell111");
            mx_lls(spisok, argv[i]);

            if (stat(argv[i], &file_statistics) == 0){
                if (S_ISDIR(file_statistics.st_mode)) {
                    mx_push_front(&dir_list, argv[i]);
                }
                else {
                    mx_push_front(&file_list, argv[i]);
                }
            }
            else {
                mx_uncreated_file(argv[i]);
            }
        }
        mx_bubble_list_sort(file_list);
        mx_bubble_list_sort(dir_list);
        if (file_list != NULL)
            //mx_printstr("hell");
            mx_lls(file_list, ".");
        bool flag = false; 
        if (dir_list != NULL && dir_list->next != NULL)
            flag = true;
        for(; dir_list != NULL; dir_list = dir_list->next){
            if (flag){
                mx_printstr("\n");
                mx_printstr(dir_list->data);
                mx_printstr(":\n");
            }

            DIR *dir = opendir(dir_list->data);
            //mx_printstr("hell");
            mx_lls(mx_return_spisok(dir), dir_list->data);
            closedir(dir);
        }
    }
}



void mx_check_G(int argc, char* argv[]) {
    if (argc == 2) {
        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); 
        }
        t_list *spisok = mx_return_spisok(dir);
        mx_print_G(spisok, ".");
        closedir(dir);
    }
    else if (argc >= 3) {
        t_list *file_spisok = mx_list_file(argc, argv, 2);
        t_list *dir_spisok = mx_list_dir(argc, argv, 2); 
        mx_print_G(file_spisok, ".");
        mx_print_dir_G(dir_spisok);
    }
}

void mx_check_a() {
    DIR *dir = opendir(".");
    if (!dir) {
        mx_uncreated_file("."); 
    }
    t_list *spisok = mx_return_spisok_with_dot(dir);
    mx_print_column(spisok);
    closedir(dir);
}

void mx_check_A() {
    DIR *dir = opendir(".");
    if (!dir) {
        mx_uncreated_file("."); 
    }
    t_list *spisok = mx_return_spisok_with_hiden(dir);
    mx_print_column(spisok);
    closedir(dir);
}

void mx_check_row() {
    DIR *dir = opendir(".");
    if (!dir) {
        mx_uncreated_file("."); 
    }
    t_list *spisok = mx_return_spisok(dir);
    mx_print_row(spisok);
    closedir(dir);
}

void mx_check_col() {
    DIR *dir = opendir(".");
    if (!dir) {
        mx_uncreated_file("."); 
    }
    t_list *spisok = mx_return_spisok(dir);
    mx_print_column(spisok);
    closedir(dir);
    
}

void mx_check_m() {
    DIR *dir = opendir(".");
    if (!dir) {
        mx_uncreated_file("."); 
    }
    t_list *spisok = mx_return_spisok(dir);
    mx_print_with_coma(spisok);
    closedir(dir);
}

