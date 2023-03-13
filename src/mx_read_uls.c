#include "../inc/uls.h"


void mx_ls(char* argv[]) {
    DIR *limon;
    if (argv[1]) {
        limon = opendir(argv[1]);
    }
    else {
        limon = opendir("apelsin");
    }
    struct dirent *dir;
    mx_printstr("proverka na vhod 1\n");
    t_list *head = mx_create_node((void *) "LIME");
    mx_printstr("proverka na vhod 2\n");
    while ((dir = readdir(limon))) {
        mx_push_front(&head, dir->d_name);
    }
    for (t_list *i = head; i->next != NULL; i = i->next) {
        mx_printstr(i->data);
        mx_printchar('\n');
    }
    mx_printstr("proverka na vhod 3\n");
    // mx_sort_list(head, *mx_strcmp);
    // mx_printstr("proverka na vhod 4\n");
    
    closedir(limon);
}


