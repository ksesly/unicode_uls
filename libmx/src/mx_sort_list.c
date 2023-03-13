#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, int (*cmp)(const char *, const char *)) {
    if (lst == NULL || cmp == NULL) 
        return NULL;
    for (t_list *s1 = lst; s1 != NULL; s1 = s1->next) {
        if (cmp(s1->data, s1->next->data)) {
            void *temp  = s1->data;
            s1->data = s1->next->data;
            s1->next->data = temp;
        }
    }
    return lst;
}



