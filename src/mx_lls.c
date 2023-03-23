#include "../inc/uls.h"


 void mx_lls(t_list *spisok, char *path) {
    char buff[200];
    mx_bubble_list_sort(spisok);

    int max_size = mx_int_length(spisok, path);
    struct stat file_statistics;

    mx_printstr("total ");
    mx_printint(mx_total(spisok, path));
    mx_printchar('\n');

    for (t_list *i = spisok; i != NULL; i = i->next) {
        sprintf(buff, "%s/%s", path, i->data);
        if (stat(buff, &file_statistics) == -1) continue;
        mx_print_lls(file_statistics, max_size);

        // print the file name
        mx_printstr(i->data);
        mx_printchar('\n');
    }
}


void mx_print_lls(struct stat file_statistics, int max_size) {

    struct passwd *pw;
    struct group *grp;

    // print the accesss
    mx_print_file_access(file_statistics);
    mx_printstr("  ");

    // print the useness
    mx_printint(file_statistics.st_nlink);
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
