#include "../inc/uls.h"

t_list *mx_return_spisok(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        if (head->d_name[0] == '.') 
           continue;
        mx_push_front(&spisok, mx_strdup(head->d_name));
    } 
    mx_bubble_list_sort(spisok); 
    return spisok;
}

t_list *mx_return_spisok_with_dot(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        mx_push_front(&spisok, mx_strdup(head->d_name));
    }
    mx_bubble_list_sort(spisok);
    return spisok;
}

t_list *mx_return_spisok_with_hiden(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        if (head->d_name[0] == '.' && head->d_name[1] != '.' && mx_strlen(head->d_name) > 1)
            mx_push_front(&spisok, mx_strdup(head->d_name));
        else if (head->d_name[0] != '.')
            mx_push_front(&spisok, mx_strdup(head->d_name));
    }
    mx_bubble_list_sort(spisok);
    return spisok;
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
            mx_printerr("uls: ");
            perror(argv[i]);
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

    }
    mx_bubble_list_sort(dir_spisok);
    return dir_spisok;
}

int mx_list_dir_int(int argc, char *argv[], int i){
    int n = 0;
    struct stat file_statistics;
    for (; i < argc; i++){
        if (stat(argv[i], &file_statistics) == 0){
            if (S_ISDIR(file_statistics.st_mode)) {
                n++;
            }
            else {
                continue;
            }
        }
        else {
            n++;
        }

    }
    return n;
}

t_list *mx_return_r_spisok(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        if (head->d_name[0] == '.') 
           continue;
        mx_push_front(&spisok, head->d_name);
    } 
    mx_bubble_r_list_sort(spisok); 
    return spisok;
}

t_list *mx_list_r_file(int argc, char *argv[], int i){
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
            mx_printerr("uls: ");
            perror(argv[i]);
        }
    }
    mx_bubble_r_list_sort(file_spisok);
    return file_spisok;
}

t_list *mx_list_r_dir(int argc, char *argv[], int i){
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
    }
    mx_bubble_r_list_sort(dir_spisok);
    return dir_spisok;
}



