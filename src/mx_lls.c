#include "../inc/uls.h"


 void mx_lls(t_list *spisok) {
    mx_bubble_list_sort(spisok);
    //mx_printstr("suka, ");

    struct stat file_statistics;
    //struct tm *tm;
    struct passwd *pw;
    struct group *grp;


    for (t_list *i = spisok; i->next != NULL; i = i->next) {
        if (stat(i->data, &file_statistics) == -1) {
            continue;
        }
        
        //mx_printchar('\n');
    //     print the format
        mx_printint(file_statistics.st_mode);
        mx_printchar(' ');

    //     print the useness?
         mx_printint(file_statistics.st_nlink);
         mx_printchar(' ');

        // //print the owner`s id
        pw = getpwuid(file_statistics.st_uid);
        mx_printstr(pw->pw_name);

        mx_printchar(' ');

        // //print the name
        grp = getgrgid(file_statistics.st_gid);
        mx_printstr(grp->gr_name);
        mx_printchar(' ');

    //     print the size
        mx_printint((__intmax_t)file_statistics.st_size);
        mx_printchar(' ');



    //     mx_printchar(' ');
    //     print the data and time 
        
        mx_printstr(mx_trimtime(ctime(&file_statistics.st_mtime)));
        mx_printchar(' ');

    //     print the file name
        mx_printstr(i->data);
        mx_printchar('\n');


    //     mx_printchar('\n');
    }
    //mx_printchar('\n');
}


char* mx_trimtime(char* tupaya_stroka) {
    char* umnaya_stroka = malloc(12);
    for (int i = 0; i < 12; i++) {
        umnaya_stroka[i] = tupaya_stroka[i+4]; 
    }
    umnaya_stroka[12] = '\0';
    return umnaya_stroka;
}

