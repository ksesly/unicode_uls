#include "../inc/uls.h"


void mx_full_ls_function(char* argv[], int argc) {
    if (argc == 1){
        DIR *dir = opendir(".");

        if (!dir) {
            mx_uncreated_file("."); //dorabotat chtob (obrabotat posl argv)
        }

        t_list *spisok = mx_return_spisok(dir);
        mx_ls(spisok);
        closedir(dir);
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
            mx_uncreated_file("."); //dorabotat chtob (obrabotat posl argv)
        }
        t_list *spisok = mx_return_spisok(dir);
        mx_bubble_list_sort(spisok);
        mx_print_row(spisok);
        closedir(dir);
    }
    else if (mx_strcmp(argv[1], "-C") == 0){
        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); //dorabotat chtob (obrabotat posl argv)
        }
        t_list *spisok = mx_return_spisok(dir);
        mx_bubble_list_sort(spisok);
        mx_print_column(spisok);
        closedir(dir);
    }
    else if (mx_strcmp(argv[1], "-a") == 0){
        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); //dorabotat chtob (obrabotat posl argv)
        }
        t_list *spisok = mx_return_spisok_with_dot(dir);
        mx_print_column(spisok);
        closedir(dir);
    }
    else if (mx_strcmp(argv[1], "-A") == 0){
        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); //dorabotat chtob (obrabotat posl argv)
        }
        t_list *spisok = mx_return_spisok_with_hiden(dir);
        mx_print_column(spisok);
        closedir(dir);
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
            
            DIR *dir = opendir(dir_spisok->data);

            mx_printstr(dir_spisok->data);
            mx_printstr(":\n");
            t_list *sp = mx_return_spisok(dir);
            mx_no_flags(sp);
            mx_printchar('\n');
            closedir(dir);
            dir_spisok = dir_spisok->next;
        }
    }
}

t_list *mx_return_spisok(DIR *dir){
    struct dirent *head;
    t_list *spisok = mx_create_node((void *) "LIME");
    while ((head = readdir(dir))) {
        if (head->d_name[0] == '.') 
           continue;
        mx_push_front(&spisok, head->d_name);
    }
    mx_pop_back(&spisok); //VSTAVIT BUBLE SORT I YDALIT EGO VEZDE GDE WE PRIMENAYEM EGO POSLE 
    return spisok;
}

t_list *mx_return_spisok_with_dot(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        mx_push_front(&spisok, head->d_name);
    }
    mx_bubble_list_sort(spisok);
    return spisok;
}

t_list *mx_return_spisok_with_hiden(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        if (head->d_name[0] == '.' && head->d_name[1] != '.' && mx_strlen(head->d_name) > 1)
            mx_push_front(&spisok, head->d_name);
        else if (head->d_name[0] != '.')
            mx_push_front(&spisok, head->d_name);
    }
    mx_bubble_list_sort(spisok);
    return spisok;
}

