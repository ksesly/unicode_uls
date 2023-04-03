#include "../inc/uls.h"

t_list *mx_return_spisok(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        if (head->d_name[0] == '.') 
           continue;
        mx_push_front(&spisok, head->d_name);
    } 
    mx_bubble_list_sort(spisok); 
    return spisok;
}

t_list *mx_return_spisok_with_dot(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        mx_push_front(&spisok, head->d_name);
    }
    mx_bubble_list_sort(spisok);
    return spisok;
}

t_list *mx_return_spisok_with_hiden(DIR *dir){
    struct dirent *head;
    t_list *spisok = NULL;
    while ((head = readdir(dir))) {
        if (head->d_name[0] == '.' && head->d_name[1] != '.' && mx_strlen(head->d_name) > 1)
            mx_push_front(&spisok, head->d_name);
        else if (head->d_name[0] != '.')
            mx_push_front(&spisok, head->d_name);
    }
    mx_bubble_list_sort(spisok);
    return spisok;
}


