#include "../inc/uls.h"

// ls command implementation without flags

void mx_ls(t_list *spisok) {
   
    mx_bubble_list_sort(spisok);
    t_list *i = spisok;
    for (; i->next != NULL; i = i->next) {
        mx_printstr(mx_strcat(i->data, "  "));
    }
    mx_printstr(mx_strcat(i->data, "  "));
    mx_printchar('\n');
    
}


