#include "../inc/uls.h"


 void mx_lls(t_list *spisok, char *path) {

    int max_size = mx_int_length(spisok, path);
    int max_number = mx_number_length(spisok, path);
    struct stat file_statistics;
    
    if (path[0] != '.'){
        mx_print_total(spisok, path);
    }
    
    for (t_list *i = spisok; i != NULL; i = i->next) {
        char *buff = malloc(mx_strlen(path + 1) + mx_strlen(i->data));
        mx_strcat(buff, mx_strdup(path));

        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);

        if (lstat(buff, &file_statistics) == -1) continue;

        mx_print_lls(file_statistics, max_size, max_number, buff);

        mx_printstr(i->data);
        if (S_ISLNK(file_statistics.st_mode)) {
            mx_printstr(" -> ");
            char *temp = malloc(1024 * sizeof(char));
            ssize_t length = readlink(buff, temp, sizeof(temp));
            temp[length] = '\0';
            
            mx_printstr(mx_strcat(temp, i->data));
            free(temp);
        }
        mx_printchar('\n');
    }
}

void mx_print_lls(struct stat file_statistics, int max_size, int max_number, char* filename) {

    struct passwd *pw;
    struct group *grp;
    
    mx_print_file_access(file_statistics);
    acl_t tmp;

    if (listxattr(filename, NULL, 0, XATTR_NOFOLLOW) > 0) {
        mx_printchar('@');
        mx_printchar(' ');
    }
    else if ((tmp = acl_get_file(filename, ACL_TYPE_EXTENDED)) != NULL) {
        acl_free(tmp);
        mx_printchar('+');
        mx_printchar(' ');
    }
    else {
        mx_printstr("  ");
    }
    mx_print_size(max_number, file_statistics.st_nlink);
    mx_printchar(' ');

    pw = getpwuid(file_statistics.st_uid);
    mx_printstr(pw->pw_name);
    mx_printstr("  ");

    grp = getgrgid(file_statistics.st_gid);
    mx_printstr(grp->gr_name);
    mx_printstr("  ");

    mx_print_size(max_size, file_statistics.st_size);
    mx_printchar(' ');

    int t = time(NULL) - file_statistics.st_mtime;
    if (t > (60 * 60 * 12 * 365)) {
        mx_printstr(mx_trim_year(ctime(&file_statistics.st_mtime)));
        mx_printchar(' ');
        char* temp = ctime(&file_statistics.st_mtime) + 20;
        for (int i = 0; i < 4; i++) {
            mx_printchar(temp[i]);
        }
    }
    else {
        mx_printstr(mx_trimtime(ctime(&file_statistics.st_mtime)));
    }
    
    mx_printchar(' ');
}

