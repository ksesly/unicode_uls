#include "../inc/uls.h"



void mx_full_ls_function(char* argv[], int argc) {
    if (argc == 1){

        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); 
        }
        t_list *spisok = mx_return_spisok(dir);
        mx_ls(spisok);
        closedir(dir);
    }
    else if (mx_strcmp(argv[1], "-m") == 0){
        mx_check_m();
    }
    else if (mx_strcmp(argv[1], "-m") == 0){
        if (argc == 2)
            mx_check_m();
        else
            mx_ebatb_I_smart_peredal_function_in_other_function(&mx_print_with_coma, argc, argv, 2);
        
    }
    else if (mx_strcmp(argv[1], "-G") == 0){
        mx_check_G(argc, argv);
    }
    else if (mx_strcmp(argv[1], "-l") == 0){
        mx_check_l(argc, argv);
    }
    else if (mx_strcmp(argv[1], "-1") == 0){
        mx_check_row();
    }
    else if (mx_strcmp(argv[1], "-C") == 0){
        mx_check_col();
    }
    else if (mx_strcmp(argv[1], "-a") == 0){
        mx_check_a();
    }
    else if (mx_strcmp(argv[1], "-A") == 0){
        mx_check_A();
    }
    else if (mx_strcmp(argv[1], "-R") == 0){
        mx_Rls(argc, argv);
    }
    else if (mx_strcmp(argv[1], "-r") == 0){
        mx_check_r_sort(argc, argv);
    }
    else if (mx_strcmp(argv[1], "-l") != 0){
        bool is_already = true;
        t_list *file_spisok = mx_list_file(argc, argv, 1);
        t_list *dir_spisok = mx_list_dir(argc, argv, 1);

        if (dir_spisok->next == NULL && file_spisok == NULL) {
            DIR *dir = opendir(dir_spisok->data);
            if (!dir) {
                mx_uncreated_file(".");
            }

            t_list *sp = mx_return_spisok(dir);
            mx_no_flags(sp);
            //mx_printchar('\n');
            closedir(dir);
            is_already = false;
        }

        if (file_spisok != NULL) {
            while (file_spisok != NULL){
                mx_printstr(file_spisok->data);
                mx_printstr("  ");
                file_spisok = file_spisok->next;
            }
            mx_printchar('\n');
            mx_printchar('\n');
        }     


        if (dir_spisok->next != NULL) {
            while (dir_spisok != NULL){
               
                DIR *dir = opendir(dir_spisok->data);
                if (!dir) {
                    mx_uncreated_file(".");
                }
                t_list *sp = mx_return_spisok(dir);
                mx_printstr(dir_spisok->data);
                mx_printstr(":\n");
                mx_no_flags(sp);
                //mx_printchar('\n');
                if (dir_spisok->next != NULL) {
                    mx_printchar('\n');
                }
                dir_spisok = dir_spisok->next;
            }
        }
        else if (dir_spisok != NULL && is_already) {
            DIR *dir = opendir(dir_spisok->data);
                if (!dir) {
                    mx_uncreated_file(".");
                }
                t_list *sp = mx_return_spisok(dir);
                mx_printstr(dir_spisok->data);
                mx_printstr(":\n");
                mx_no_flags(sp);
        }
        //mx_printstr("hello!!!!!!!!!");
        //mx_ebatb_I_smart_peredal_function_in_other_function(&mx_print_column, argc, argv, 1);

    }
}

//kolya pisal etot kod
