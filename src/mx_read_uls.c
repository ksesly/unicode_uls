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

    struct stat file_stat;
    printf(" %ld ", file_stat.st_nlink);
    struct passwd *pw = getpwuid(file_stat.st_uid);
    printf("%s ", pw->pw_name);
    struct group *grp = getgrgid(file_stat.st_gid);
    printf("%s ", grp->gr_name);
    printf("%5ld ", file_stat.st_size);
    char time_buf[100];
    strftime(time_buf, sizeof(time_buf), "%b %d %H:%M", localtime(&file_stat.st_mtime));
    printf("%s ", time_buf);
    printf("%s\n", filename);

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


