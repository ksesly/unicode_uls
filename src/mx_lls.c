#include "../inc/uls.h"


 void mx_lls(t_list *spisok, char *path) {
    // char buff[200];

    int max_size = mx_int_length(spisok, path);
    int max_number = mx_number_length(spisok, path);
    struct stat file_statistics;
    
    if (path[0] != '.'){
        mx_print_total(spisok, path);
    }
    
    for (t_list *i = spisok; i != NULL; i = i->next) {
        char *buff = mx_strdup(path);
        mx_strcat(buff, "/");
        mx_strcat(buff, i->data);
        // sprintf(buff, "%s/%s", path, i->data);
        if (lstat(buff, &file_statistics) == -1) continue;

        mx_print_lls(file_statistics, max_size, max_number, buff);
        // print the file name

        mx_printstr(i->data);
        mx_printchar('\n');
    }
}

void mx_print_lls(struct stat file_statistics, int max_size, int max_number, char* filename) {

    struct passwd *pw;
    struct group *grp;

    //cd ..char buf[512];
    // print the accesss
    mx_print_file_access(file_statistics);
    // acl_t tmp;
    //mx_printstr(filename);
    if (listxattr(filename, NULL, 0, XATTR_NOFOLLOW) > 0) {
        mx_printchar('@');

        mx_printchar(' ');
    }
    // else if ((tmp = acl_get_file(filename, ACL_TYPE_EXTENDED))) {
    //     acl_free(tmp);
    //     mx_printchar('+');
    // }
     else {
        //mx_printstr(filename);
        //mx_printint(size);
        mx_printstr("  ");
    }
    mx_print_size(max_number, file_statistics.st_nlink);
    mx_printchar(' ');

    // print the owner`s id
    pw = getpwuid(file_statistics.st_uid);
    mx_printstr(pw->pw_name);
    mx_printstr("  ");

    // print the name
    grp = getgrgid(file_statistics.st_gid);
    mx_printstr(grp->gr_name);
    mx_printstr("  ");

    // print the size
    mx_print_size(max_size, file_statistics.st_size);
    mx_printchar(' ');

    // print the data and time  
    mx_printstr(mx_trimtime(ctime(&file_statistics.st_mtime)));
    mx_printchar(' ');
}
