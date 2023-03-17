#include "../inc/uls.h"

// ls command implementation without flags

void mx_ls(char* argv[]) {
    DIR *limon = opendir(argv[1]);
    if (!limon) {
        mx_uncreated_file(argv[1]);
    } 
    struct dirent *dir;
    t_list *spisok = mx_create_node((void *) "LIME");
    while ((dir = readdir(limon))) {
        mx_push_front(&spisok, dir->d_name);
    }
    for (t_list *i = spisok; i->next != NULL; i = i->next) {
        mx_printstr(i->data);
        mx_printchar('\n');
    }
    //SDELAT` SORTIROVKU
    // mx_sort_list(head, *mx_strcmp);
    
    closedir(limon);
}


