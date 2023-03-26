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


int mx_int_length(t_list *spisok, char *path) {
    struct stat file_statistics;
    int max = 0;
    char buff[200];

    for (t_list *i = spisok; i != NULL; i = i->next) {
        sprintf(buff, "%s/%s", path, i->data);
        if (stat(buff, &file_statistics) == -1) continue;

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

int mx_number_length(t_list *spisok, char *path) {
    struct stat file_statistics;
    int max = 0;
    char buff[200];

    for (t_list *i = spisok; i != NULL; i = i->next) {
        sprintf(buff, "%s/%s", path, i->data);
        if (stat(buff, &file_statistics) == -1) continue;

        int l = file_statistics.st_nlink;
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

void mx_print_number(int max, int size) {
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


int mx_total(t_list *spisok, char *path){
    char buff[200];
    struct stat file_statistics;
    int size = 0;

    for (t_list *i = spisok; i != NULL; i = i->next){
        sprintf(buff, "%s/%s", path, i->data);
        if (stat(buff, &file_statistics) == -1) {
            perror(buff);
            continue;
            
        }
        size += file_statistics.st_blocks;
    }

    return size;
}

t_list *mx_list_file(int argc, char *argv[], int i){
    t_list *file_spisok = NULL;
    struct stat file_statistics;
    for (; i < argc; i++){
        if (stat(argv[i], &file_statistics) == 0){
            if (S_ISDIR(file_statistics.st_mode)) {
                continue;
            }
            else {
                mx_push_front(&file_spisok, argv[i]);
            }
        }
        else {
            mx_uncreated_file(argv[i]);
        }
    }
    mx_bubble_list_sort(file_spisok);
    return file_spisok;
}

t_list *mx_list_dir(int argc, char *argv[], int i){
    t_list *dir_spisok = NULL;
    struct stat file_statistics;
    for (; i < argc; i++){
        if (stat(argv[i], &file_statistics) == 0){
            if (S_ISDIR(file_statistics.st_mode)) {
                mx_push_front(&dir_spisok, argv[i]);
            }
            else {
                continue;
            }
        }
        else {
            mx_uncreated_file(argv[i]);
        }
    }
    mx_bubble_list_sort(dir_spisok);
    return dir_spisok;
}

void mx_print_row(t_list *spisok){
    for (t_list *i = spisok; i != NULL; i = i->next){
        mx_printstr(mx_strcat(i->data, "\n"));
    }
}

void mx_print_column(t_list *spisok){
    for (t_list *i = spisok; i != NULL; i = i->next){
        mx_printstr(mx_strcat(i->data, "  "));
    }
    mx_printchar('\n');
}
