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
    else if (argc > 3){
        for (int i = 2; i < argc; i++){
            DIR *dir = opendir(".");
            if (!dir) {
                mx_uncreated_file("."); 
            }
            t_list *spisok = mx_return_spisok(dir);
            mx_lls(spisok, argv[i]);
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

