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

//ls
void mx_ls(t_list *spisok);
//void mx_lls(t_list *spisok);
void mx_full_ls_function(char* argv[]);




