#include "../inc/uls.h"

// ls command implementation without flags
void bubbleSort(t_list *start) { 
    bool swapped = true; 
    t_list *ptr1 = start;
    t_list *end = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 

    while(swapped){
        ptr1 = start;
        swapped = false;
        while (ptr1->next != end){
            if (mx_strcmp(ptr1->data, ptr1->next->data) > 0){
                char* temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        end = ptr1;
    }
}


static void mx_ls(t_list *spisok) {
   
    
    //SDELAT` SORTIROVKU
    //mx_sort_list(spisok, *mx_strcmp);
    bubbleSort(spisok);
    t_list *i = spisok;
    for (; i->next != NULL; i = i->next) {
        mx_printstr(mx_strcat(i->data, "  "));
    }
    mx_printstr(mx_strcat(i->data, "  "));
    
}


//static void mx_lls(/*t_list *spisok*/) {
    //mx_printstr("suka");
    //struct stat file_statistics;
    //for (t_list *i = spisok; i->next != NULL; i = i->next) {
        
        //print the format


        //mx_printchar(' ');
        //print the useness?
        //mx_printint(file_statistics.st_nlink);
        //mx_printchar(' ');
        //print the owner`s id
        // struct passwd *pw = getpwuid(file_statistics.st_uid);
        // mx_printstr(pw->pw_name);
        // mx_printchar(' ');
        //print the name
        // struct group *grp = getgrgid(file_statistics.st_gid);
        // mx_printstr(grp->gr_name);
        // mx_printchar(' ');
        //print the size
        //mx_printint(file_statistics.st_size);

        //mx_printchar(' ');  
        //??

        //mx_printchar(' ');
        //print the data and time 


        //mx_printchar(' ');
        //ptinttime

        //print the file name
        //mx_printstr(i->data);
        //mx_printchar('\n');


        //mx_printchar('\n');
    //}

//}

void mx_full_ls_function(char* argv[]) {
    //mx_printstr("hello suka");
    DIR *limon = opendir(argv[1]);
    if (!limon) {
        mx_uncreated_file(argv[1]); //dorabotat chtob (obrabotat posl argv)
    } 
    struct dirent *dir;
    t_list *spisok = mx_create_node((void *) "LIME");
    while ((dir = readdir(limon))) {
        if (dir->d_name[0] == '.') //kostyl
           continue;
        mx_push_front(&spisok, dir->d_name);
    }
    mx_pop_back(&spisok);

    //SDELAT` PRVERKU ARGUMENTOV NA FLAGI
    //OT NIH ZAVISIT VYVOD
    //mx_lls(/*spisok*/);
    // mx_printchar('\n');
    mx_ls(spisok); //PUST` POKA CHTO BUDET DLYA PROVERKI RABOTY

    closedir(limon);

}


