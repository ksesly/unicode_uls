#include "../inc/uls.h"

// int mx_find_last_argument(int argc) {
//     int last;
//     for (last = 0; last < argc; last++);
//     return last;
// }

void mx_bubble_list_sort(t_list *start) { 
    bool swapped = true; 
    t_list *ptr1 = start;
    t_list *end = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 

    while(swapped){
        ptr1 = start;
        swapped = false;
        while (ptr1->next != end){
            if (mx_strcmp(ptr1->data, ptr1->next->data) > 0){
                char* temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        end = ptr1;
    }
}

