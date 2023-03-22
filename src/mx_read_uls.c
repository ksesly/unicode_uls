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
    if (mx_strcmp(argv[1], "-l") == 0){
        if (argc == 2){
            DIR *dir = opendir(".");

            if (!dir) {
                mx_uncreated_file("."); //dorabotat chtob (obrabotat posl argv)
            }

            t_list *spisok = mx_return_spisok(dir);
            mx_lls(spisok);
            closedir(dir);
        }
        else if (argc == 3){
            for (int i = 2; i < argc; i++){
                DIR *dir = opendir(argv[i]);

                if (!dir) {
                    mx_uncreated_file(argv[i]); //dorabotat chtob (obrabotat posl argv)
                }

                t_list *spisok = mx_return_spisok(dir);
                mx_lls(spisok);
                closedir(dir);
            }
        }
    }
    
    

    //SDELAT` PRVERKU ARGUMENTOV NA FLAGI
    //OT NIH ZAVISIT VYVOD

    //mx_ls(spisok); //PUST` POKA CHTO BUDET DLYA PROVERKI RABOTY


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

