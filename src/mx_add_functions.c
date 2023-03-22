#include "../inc/uls.h"

void mx_bubble_list_sort(t_list *start) { 
    bool swapped = true; 
    t_list *list = start;
    t_list *end = NULL; 
  
    if (start == NULL) 
        return; 

    while(swapped){
        list = start;
        swapped = false;
        while (list->next != end){
            if (mx_strcmp(list->data, list->next->data) > 0) {
                char* temp = list->data;
                list->data = list->next->data;
                list->next->data = temp;

                swapped = true;
            }
            list = list->next;
        }
        end = list;
    }
}


char* mx_trimtime(char* str) {
    char* n_str = malloc(12);
    for (int i = 0; i < 12; i++) {
        n_str[i] = str[i+4]; 
    }
    n_str[12] = '\0';
    return n_str;
}


int mx_int_length(t_list *spisok) {
    struct stat file_statistics;
    int max = 0;

    for (t_list *i =  spisok; i != NULL; i = i->next) {

        if (stat(i->data, &file_statistics) == -1) continue;

        int l = file_statistics.st_size;
        int temp = 0;
        while (l > 0){
            l /= 10;
            temp++;
        }
        if (temp > max)
            max = temp;
        
    }
    return max;
}


void mx_print_size(int max, int size) {
    int s = size;
    int temp = 0;

    while (s > 0){
        s /= 10;
        temp++;
    }

    for (; temp < max; temp++)
        mx_printchar(' ');

    mx_printint(size);
}


int mx_total(t_list *spisok){
    struct stat file_statistics;
    int size = 0;

    for (t_list *i = spisok; i != NULL; i = i->next){
        if (stat(i->data, &file_statistics) == -1) {
            perror(i->data);
            continue;
            
        }
        size += file_statistics.st_blocks;
    }

    return size;
}
