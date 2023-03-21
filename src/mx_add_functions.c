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

char* mx_trimtime(char* tupaya_stroka) {
    char* umnaya_stroka = malloc(12);
    for (int i = 0; i < 12; i++) {
        umnaya_stroka[i] = tupaya_stroka[i+4]; 
    }
    umnaya_stroka[12] = '\0';
    return umnaya_stroka;
}

int mx_int_length(t_list *spisok){
    struct stat file_statistics;
    int max = 0;

    for (t_list *i =  spisok; i != NULL; i = i->next){
        if (stat(i->data, &file_statistics) == -1) {
            continue;
        }
        int l = file_statistics.st_size;
        int temp = 0;
        while (l > 0){
            l /= 10;
            temp++;
        }
        if (temp > max){
            max = temp;
        }
    }

    return max;
}

void mx_print_size(int max, int size){
    int s = size;
    int temp = 0;

    while (s > 0){
        s /= 10;
        temp++;
    }
    for (; temp < max; temp++){
        mx_printchar(' ');
    }
    mx_printint(size);
}

int mx_total(t_list *spisok){
    struct stat file_statistics;
    int size = 0;

    for (t_list *i =  spisok; i != NULL; i = i->next){
        if (stat(i->data, &file_statistics) == -1) {
            continue;
        }
        size += file_statistics.st_blocks;
        
    }

    return size;
}
