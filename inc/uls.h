#pragma once

#include "../libmx/inc/libmx.h"
#include <dirent.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>


//errors
void mx_uls_errors_checker(int argc);
void mx_uncreated_file(char* oshibka);

//void mx_format_error(void);

//additional functions

void mx_bubble_list_sort(t_list *start);
char* mx_trimtime(char* tupaya_stroka);
void mx_print_file_access(struct stat file_stat);
int mx_int_length(t_list *spisok);
void mx_print_size(int max, int size);
int mx_total(t_list *spisok);

//ls
//void mx_ls(t_list *spisok);
void mx_lls(t_list *spisok);
void mx_full_ls_function(char* argv[]);
void mx_print_lls(struct stat file_statistics, int max);






