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
    else if (mx_strcmp(argv[1], "-l") == 0){
        if (argc == 2){
            DIR *dir = opendir(".");

            if (!dir) {
                mx_uncreated_file("."); //dorabotat chtob (obrabotat posl argv)
            }

            t_list *spisok = mx_return_spisok(dir);
            mx_lls(spisok, ".");
            closedir(dir);
        }
        else if (argc == 3){
            for (int i = 2; i < argc; i++){
                DIR *dir = opendir(argv[i]);

                if (!dir) {
                    mx_uncreated_file(argv[i]); //dorabotat chtob (obrabotat posl argv)
                }

                t_list *spisok = mx_return_spisok(dir);
                mx_lls(spisok, argv[i]);
                closedir(dir);
            }
        }
    }
    else if (mx_strcmp(argv[1], "-l") != 0){
        t_list *spisok = NULL;
        struct stat file_statistics;
        for (int i = 1; i < argc; i++){
            if (stat(argv[i], &file_statistics) == 0){
                if (S_ISDIR(file_statistics.st_mode)) {
                    mx_push_back(&spisok, argv[i]);
                }
                else {
                    mx_push_front(&spisok, argv[i]);
                }
            }
            else {
                mx_uncreated_file(argv[i]);
            }
        }
        while (spisok != NULL){
            stat(spisok->data, &file_statistics);

            if (S_ISDIR(file_statistics.st_mode)) {
                mx_printchar('\n');
                
                DIR *dir = opendir(spisok->data);

                mx_printstr(spisok->data);
                mx_printstr(":\n");
                t_list *sp = mx_return_spisok(dir);
                mx_no_flags(sp);
                mx_printchar('\n');
                closedir(dir);
            }
            else {
                mx_printstr(spisok->data);
                mx_printstr("  ");
            }
            spisok = spisok->next;
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
    mx_pop_back(&spisok);
    return spisok;
}

