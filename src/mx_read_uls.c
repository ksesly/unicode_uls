#include "../inc/uls.h"

// ls command implementation without flags

static void mx_ls(t_list *spisok) {
   
    for (t_list *i = spisok; i->next != NULL; i = i->next) {
        mx_printstr(i->data);
        mx_printchar('\n');
    }
    //SDELAT` SORTIROVKU
    // mx_sort_list(head, *mx_strcmp);
    
}

static void mx_lls() {

    struct stat file_statistics;

    mx_printint(file_statistics.st_nlink);
    struct passwd *pw = getpwuid(file_statistics.st_uid);
    mx_printstr(pw->pw_name);
    mx_printchar(' ');
    struct group *grp = getgrgid(file_statistics.st_gid);
    mx_printstr(grp->gr_name);
    mx_printchar(' ');
    printf("%5ld ", file_statistics.st_size);
    char time_buf[100];
    strftime(time_buf, sizeof(time_buf), "%b %d %H:%M", localtime(&file_statistics.st_mtime));
    mx_printstr(time_buf);
    mx_printchar(' ');
    mx_printstr(filename);
    mx_printchar('\n');

}

void mx_full_ls_function(char* argv[]) {

     DIR *limon = opendir(argv[1]);
    if (!limon) {
        mx_uncreated_file(argv[1]);
    } 
    struct dirent *dir;
    t_list *spisok = mx_create_node((void *) "LIME");
    while ((dir = readdir(limon))) {
        if (dir->d_name == '.') 
            continue;
        mx_push_front(&spisok, dir->d_name);
    }

    //SDELAT` PRVERKU ARGUMENTOV NA FLAGI
    //OT NIH ZAVISIT VYVOD

    mx_ls(spisok); //PUST` POKA CHTO BUDET DLYA PROVERKI RABOTY

    closedir(limon);

}


