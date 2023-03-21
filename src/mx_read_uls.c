#include "../inc/uls.h"


void mx_full_ls_function(char* argv[]) {
    DIR *dir = opendir(argv[1]);
    if (!dir) {
        mx_uncreated_file(argv[1]); //dorabotat chtob (obrabotat posl argv)
    }
    struct dirent *head;
    t_list *spisok = mx_create_node((void *) "LIME");
    while ((head = readdir(dir))) {
        if (head->d_name[0] == '.') 
           continue;
        mx_push_front(&spisok, head->d_name);
    }
    mx_pop_back(&spisok);

    //SDELAT` PRVERKU ARGUMENTOV NA FLAGI
    //OT NIH ZAVISIT VYVOD

    mx_lls(spisok);
    //mx_ls(spisok); //PUST` POKA CHTO BUDET DLYA PROVERKI RABOTY

    closedir(dir);

}


