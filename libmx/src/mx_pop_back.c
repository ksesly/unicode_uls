#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    t_list *temp = *head;
    if (head == NULL || *head == NULL) 
        return;
    while (temp->next != NULL) 
        temp = temp->next;
    free(temp);
    temp = NULL;
}




