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
int mx_int_length(t_list *spisok, char *path);
void mx_print_size(int max_int, int size);
int mx_total(t_list *spisok, char *path);
t_list *mx_list_dir(int argc, char *argv[], int i);
t_list *mx_list_file(int argc, char *argv[], int i);
void mx_print_row(t_list *spisok);
void mx_print_column(t_list *spisok);
t_list *mx_return_spisok_with_dot(DIR *dir);
t_list *mx_return_spisok_with_hiden(DIR *dir);
t_list *mx_dir_man(char* direct);
int mx_number_length(t_list *spisok, char *path);

//ls
void mx_ls(t_list *spisok);
void mx_lls(t_list *spisok, char *path);
void mx_full_ls_function(char* argv[], int argc);
void mx_print_lls(struct stat file_statistics, int max_size, int max_number);
t_list *mx_return_spisok(DIR *dir);
void mx_no_flags(t_list *spisok);
void mx_print_dir_G(t_list *dir_spisok);
void mx_print_G(t_list *spisok, char *dir);
void mx_print_with_coma(t_list *spisok);

//flags
void mx_check_l(int argc, char* argv[]);
void mx_check_G(int argc, char* argv[]);
void mx_check_a();
void mx_check_A();
void mx_check_row();
void mx_check_col();
void mx_check_m();


