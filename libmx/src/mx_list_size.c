#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int size = 0;
    if (list == NULL)
        return 0;
    while (list->next != NULL) {
        size++;
        list = list->next;
    }
    return size;
}


