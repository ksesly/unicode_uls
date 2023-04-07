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
        sprintf(buff, "%s/%s", path, i->data);              //CHANGE
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
        sprintf(buff, "%s/%s", path, i->data);              //CHANGE
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
        if (i->next == NULL){
            char *buff = mx_strdup(i->data);
            mx_printstr(buff);
            mx_printstr("\n");
        }
        else{
            char *buff = mx_strdup(i->data);
            mx_printstr(buff);
            mx_printstr("  ");
        }
    }
}

void mx_print_with_coma(t_list *spisok) {
    for (t_list *i = spisok; i != NULL; i = i->next) {
        if (i->next == NULL) 
            mx_printstr(mx_strcat(i->data, "\n"));
        
        else 
            mx_printstr(mx_strcat(i->data, ", "));
    }
}



void mx_ebatb_I_smart_peredal_function_in_other_function(void (*f)(t_list *), int argc, char *argv[], int nachalo){
    bool flag = false;
        t_list *file_spisok = mx_list_file(argc, argv, nachalo);
        t_list *dir_spisok = mx_list_dir(argc, argv, nachalo);
        if (dir_spisok != NULL && dir_spisok->next == NULL && file_spisok == NULL) {

            DIR *dir = opendir(dir_spisok->data);
            if (!dir) {
                mx_uncreated_file(dir_spisok->data); 
            }
            t_list *sp = mx_return_spisok(dir);

            
            //t_list *sp = mx_dir_man(dir_spisok->data);
            f(sp);
            closedir(dir);
            //mx_printchar('\n');
        }
        if (file_spisok != NULL) {
            for (t_list *i = file_spisok; i != NULL; i = i->next){
                if (i->next == NULL){
                    mx_printstr(i->data);
                    mx_printstr("\n");
                }
                else {
                    mx_printstr(i->data);
                    mx_printstr("  ");
                }
            }
            flag = true;
        }     

        if (dir_spisok != NULL && (file_spisok != NULL || dir_spisok->next != NULL)) {
            if (flag)
                mx_printchar('\n');
            while (dir_spisok != NULL){
                DIR *dir = opendir(dir_spisok->data);
                if (!dir) {
                    mx_uncreated_file(dir_spisok->data); 
                }
                t_list *sp = mx_return_spisok(dir);
                mx_printstr(dir_spisok->data);
                mx_printstr(":\n");
                f(sp);
                //mx_printchar('\n');
                if (dir_spisok->next != NULL) {
                    mx_printchar('\n');
                }
                dir_spisok = dir_spisok->next;
                closedir(dir);
            }
        }
}

void mx_print_total(t_list *spisok, char *path){
    mx_printstr("total ");
    mx_printint(mx_total(spisok, path));
    mx_printchar('\n');
}
