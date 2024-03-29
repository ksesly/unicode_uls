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

void mx_bubble_r_list_sort(t_list *start) { 
    bool swapped = true; 
    t_list *list = start;
    t_list *end = NULL; 
  
    if (start == NULL) 
        return; 

    while(swapped){
        list = start;
        swapped = false;
        while (list->next != end){
            if (mx_strcmp(list->next->data, list->data) > 0) {
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

char* mx_trim_year(char *str) {
    char* n_str = malloc(7);
    for (int i = 0; i < 7; i++) {
        n_str[i] = str[i+4]; 
    }
    n_str[7] = '\0';
    return n_str;
}

int mx_int_length(t_list *spisok, char *path) {
    struct stat file_statistics;
    int max = 0;
    char buff[200];

    for (t_list *i = spisok; i != NULL; i = i->next) {
        mx_strcpy(buff, path);
        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);

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
        mx_strcpy(buff, path);
        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);

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

int mx_length(t_list *spisok, char *path) {
    struct passwd *pw;
    struct stat file_statistics;
    int max = 0;
    char buff[1024];

    for (t_list *i = spisok; i != NULL; i = i->next) {
        mx_strcpy(buff, path);
        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);

        if (stat(buff, &file_statistics) == -1) continue;

        pw = getpwuid(file_statistics.st_uid);

        int n = mx_strlen(pw->pw_name);
        if (n > max) {
            max = n;
        }       
    }
    return max;
}

int mx_length_group(t_list *spisok, char *path) {
    struct group *grp;
    struct stat file_statistics;
    int max = 0;
    char buff[1024];

    for (t_list *i = spisok; i != NULL; i = i->next) {
        mx_strcpy(buff, path);
        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);

        if (stat(buff, &file_statistics) == -1) continue;

        grp = getgrgid(file_statistics.st_gid);

        int n = mx_strlen(grp->gr_name);
        if (n > max) {
            max = n;
        }       
    }
    return max;
}

void mx_print_name(int max_name, struct passwd *pw) {
    char *s = pw->pw_name;
    int temp = mx_strlen(s);
    mx_printstr(pw->pw_name);
    for (; temp < max_name; temp++)
        mx_printchar(' ');
}

void mx_print_group(int max_group, struct group *grp) {
    
    char *s = grp->gr_name;
    int temp = mx_strlen(s);
    mx_printstr(grp->gr_name);
    for (; temp < max_group; temp++)
        mx_printchar(' ');
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
        mx_strcpy(buff, path);
        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);
        if (lstat(buff, &file_statistics) == -1) {
            perror(buff);
            continue;
            
        }
        size += file_statistics.st_blocks;
    }

    return size;
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


void mx_print_columnnnnnnnn(t_list *spisok) {
    int term = isatty(STDOUT_FILENO);
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int num_files = 0;
    int tabs = 2;
    char **buffer = NULL;

    if(!term) {
        for (t_list *i = spisok; i != NULL; i = i->next) {
            mx_printstr(i->data);
            mx_printchar('\n');
        }
    }
    else { 
        buffer = malloc(sizeof(char *) * num_files);
        for (int i = 0; i < num_files; i++) {
            buffer[i] = NULL;
        }
        for (t_list *i = spisok; i != NULL; i = i->next){
            num_files++;
            buffer = mx_realloc(buffer, sizeof(char *) * num_files);
            buffer[num_files - 1] = NULL;
        }
        int index = 0;
        int max_len = 0;
        for (t_list *i = spisok; i != NULL; i = i->next) {
            buffer[index] = mx_strdup(i->data);
            int len = mx_strlen(buffer[index]);
            if (len > max_len) {
                max_len = len;
            }
            index++;
        }

        if (max_len >= 4 * tabs) {
            tabs = max_len / 4 + 2;
            if (max_len > 4 * tabs) {
                tabs++;
            }
        }

        int rows = 1;

        while(true) {
            if (tabs * 4 * (num_files + 1) / rows >= w.ws_col) {
                rows++;
                continue;
            }
            break;
        }
        int columns = num_files / rows;

        if (num_files > columns * rows) {
            rows++;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (j * rows + i >= num_files) break;

                index = i + j * rows; 

                if (index >= num_files) {
                    break;
                }

                char *str = mx_strdup(buffer[index]); 

                int pad_len = tabs * 4 - mx_strlen(buffer[index]);
                if (pad_len > 0) {
                    str = mx_realloc(str, mx_strlen(str) + pad_len + 1); 
                    if (buffer[i + 1] != NULL) {
                        for (int k = 0; k < pad_len; k++) { 
                            mx_strcat(str, " ");
                        }
                    }
                }
                write(STDOUT_FILENO, str, mx_strlen(str)); 
                free(str); 
            }
            mx_printchar('\n');
        }
        for (int i = 0; i < num_files; i++) {
            free(buffer[i]);
        }
        free(buffer);
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



void mx_multi_file_and_dir_output(void (*f)(t_list *), int argc, char *argv[], int nachalo){
    bool flag = false;
    t_list *file_spisok = mx_list_file(argc, argv, nachalo);
    t_list *dir_spisok = mx_list_dir(argc, argv, nachalo);
    if (dir_spisok != NULL && dir_spisok->next == NULL && file_spisok == NULL) {
        if (dir_spisok->data == NULL) {
            return;
        }
        else {
            DIR *dir = opendir(dir_spisok->data);
            if (!dir) {
                mx_printerr("uls: ");
                perror(dir_spisok->data);
            }
            t_list *sp = mx_return_spisok(dir);
            f(sp);
            closedir(dir);  
        }
        
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
                mx_printerr("uls: ");
                perror(dir_spisok->data);
            }
            t_list *sp = mx_return_spisok(dir);
            mx_printstr(dir_spisok->data);
            mx_printstr(":\n");
            f(sp);
            if (dir_spisok->next != NULL) {
                mx_printchar('\n');
            }
            dir_spisok = dir_spisok->next;
            closedir(dir);
        }
    }
}

void mx_multi_file_and_dir_output_r_sort(void (*f)(t_list *), int argc, char *argv[], int nachalo){

        bool flag = false;
        t_list *file_spisok = mx_list_r_file(argc, argv, nachalo);
        t_list *dir_spisok = mx_list_r_dir(argc, argv, nachalo);
        if (dir_spisok != NULL && dir_spisok->next == NULL && file_spisok == NULL) {
            if (dir_spisok->data == NULL) {
                return;
            }
            else {
                DIR *dir = opendir(dir_spisok->data);
                if (!dir) {
                    mx_printerr("uls: ");
                    perror(dir_spisok->data);
                }
                t_list *sp = mx_return_r_spisok(dir);
                f(sp);
                closedir(dir); 
            }
            
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
                    mx_printerr("uls: ");
                    perror(dir_spisok->data);
                }
                t_list *sp = mx_return_r_spisok(dir);
                mx_printstr(dir_spisok->data);
                mx_printstr(":\n");
                f(sp);
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
