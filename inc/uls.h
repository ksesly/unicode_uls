#pragma once

#include "../libmx/inc/libmx.h"
#include <dirent.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <stdio.h>
#include <errno.h>

//errors
void mx_uls_errors_checker(int argc);
void mx_uncreated_file(char* oshibka);

//additional functions
void mx_bubble_list_sort(t_list *start);
char* mx_trimtime(char* str);
void mx_print_file_access(struct stat file_statistics);
int mx_int_length(t_list *spisok);
void mx_print_size(int max_int, int size);
int mx_total(t_list *spisok);

//ls
void mx_ls(t_list *spisok);
void mx_lls(t_list *spisok);
void mx_full_ls_function(char* argv[], int argc);
void mx_print_lls(struct stat file_statistics, int max);
t_list *mx_return_spisok(DIR *dir);
DIR *mx_opendir(char *s);






