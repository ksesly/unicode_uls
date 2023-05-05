#include "../inc/uls.h"


 void mx_lls(t_list *spisok, char *path) {

    int max_size = mx_int_length(spisok, path);
    int max_number = mx_number_length(spisok, path);
    int max_name = mx_length(spisok, path);
    int max_group = mx_length_group(spisok, path);

    struct stat file_statistics;
    
    if (path[0] != '.'){
        mx_print_total(spisok, path);
    }
    
    for (t_list *i = spisok; i != NULL; i = i->next) {
        char *buff = mx_strnew(mx_strlen(path + 1) + mx_strlen(i->data) + 8);
        mx_strcat(buff, mx_strdup(path));
        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);

        if (lstat(buff, &file_statistics) == -1) 
            continue;

        mx_print_lls(file_statistics, max_size, max_number, buff, max_name, max_group);

        mx_printstr(i->data);
        if (S_ISLNK(file_statistics.st_mode)) {
            mx_printstr(" -> ");
            char temp[1024];
            ssize_t length = readlink(buff, temp, sizeof(temp));
            temp[length] = '\0';
            mx_printstr(temp);
        }
        mx_printchar('\n');
        free(buff);
    }
}

void mx_print_lls(struct stat file_statistics, int max_size, int max_number, char* filename, int max_name, int max_group) {
    
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

    mx_print_name(max_name, getpwuid(file_statistics.st_uid));
    mx_printstr("  ");

    mx_print_group(max_group, getgrgid(file_statistics.st_gid));
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

void mx_dev_output() {

    struct passwd *pw;
    struct group *grp;

    struct stat file_statistics;

    if (lstat("/dev/null", &file_statistics) == -1) {
        mx_printerr("uls: ");
        perror("/dev/null");
    }

    mx_print_file_access(file_statistics);
    acl_t tmp;

    if (listxattr("/dev/null", NULL, 0, XATTR_NOFOLLOW) > 0) {
        mx_printchar('@');
        mx_printchar(' ');
    }
    else if ((tmp = acl_get_file("/dev/null", ACL_TYPE_EXTENDED)) != NULL) {
        acl_free(tmp);
        mx_printchar('+');
        mx_printchar(' ');
    }
    else {
        mx_printstr("  ");
    }

    mx_printint(file_statistics.st_nlink);
    mx_printchar(' ');

    pw = getpwuid(file_statistics.st_uid);
    mx_printstr(pw->pw_name);
    mx_printstr("  ");

    grp = getgrgid(file_statistics.st_gid);
    mx_printstr(grp->gr_name);
    mx_printstr("  ");

    mx_printint(file_statistics.st_size);
    mx_printstr(" ");

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
    mx_printstr(" /dev/null\n");
}



