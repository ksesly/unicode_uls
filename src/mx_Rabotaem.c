#include "../inc/uls.h"

void mx_Rls(int argc, char *argv[]){
    if (argc == 2){
        DIR *dir = opendir(".");
        if (!dir) {
            mx_uncreated_file("."); 
        }
        struct stat file_statistics;
        t_list *spisok = mx_return_spisok(dir);

        //mx_printstr(".:\n");
        //mx_print_column(spisok);
        mx_print_columnnnnnnnn(spisok);
        for (t_list *i = spisok; i != NULL; i = i->next){
            char *buff = mx_strdup(".");
            mx_strcat(buff, "/");
            mx_strcat(buff, i->data);
            
            if (stat(i->data, &file_statistics) == -1) continue;
            
            if (S_ISDIR(file_statistics.st_mode)){
                mx_printstr("\n");
                mx_tipa_recyrsia(buff);
            }
            else {
                continue;
            }
        }

        closedir(dir);
    }
    else if (argc > 2){
        bool flag = false;
        t_list *file_spisok = mx_list_file(argc, argv, 2);
        t_list *dir_spisok = mx_list_dir(argc, argv, 2);
        if (dir_spisok != NULL && dir_spisok->next == NULL && file_spisok == NULL) {

             DIR *dir = opendir(dir_spisok->data);
            if (!dir) {
                 mx_uncreated_file(dir_spisok->data); 
             }
             t_list *sp = mx_return_spisok(dir);

             mx_print_columnnnnnnnn(sp);
            //mx_tipa_recyrsia(dir_spisok->data);
            closedir(dir);
            //mx_printchar('\n');
        }
        if (file_spisok != NULL) {
            //for (t_list *i = file_spisok; i != NULL; i = i->next){
                // if (i->next == NULL){
                //     mx_printstr(i->data);
                //     mx_printstr("\n");
                // }
                // else {
                //     mx_printstr(i->data);
                //     mx_printstr("  ");
                // }

                mx_print_columnnnnnnnn(file_spisok);
            //}
            flag = true;
        }     

        if (dir_spisok != NULL && (file_spisok != NULL || dir_spisok->next != NULL)) {
            if (flag)
                mx_printchar('\n');
            while (dir_spisok != NULL){
                // DIR *dir = opendir(dir_spisok->data);
                // if (!dir) {
                //     mx_uncreated_file(dir_spisok->data); 
                // }
                // t_list *sp = mx_return_spisok(dir);
                // mx_printstr(dir_spisok->data);
                // mx_printstr(":\n");
                mx_tipa_recyrsia(dir_spisok->data);
                //mx_printchar('\n');
                if (dir_spisok->next != NULL) {
                    mx_printchar('\n');
                }
                dir_spisok = dir_spisok->next;
                //closedir(dir);
            }
        }
    }
}

void mx_tipa_recyrsia(char *path){
    DIR *dir = opendir(path);


    t_list *spisok = mx_return_spisok(dir);
    //mx_printstr("\n");
    mx_printstr(path);
    mx_printstr(":\n");
    mx_print_columnnnnnnnn(spisok);
    for (t_list *i = spisok; i != NULL; i = i->next){
        struct stat file_statistics;
        char route_in_file[1024];

        sprintf(route_in_file, "%s/%s", path, i->data);
        if (stat(route_in_file, &file_statistics) == -1){
            continue;
        }
        if (S_ISDIR(file_statistics.st_mode)){
            mx_printstr("\n");
            mx_tipa_recyrsia(route_in_file);
        }
    }

    closedir(dir);
}
