#include "../inc/uls.h"

void mx_gls(t_list *spisok) {

	//char buff[200];
	const char* blue_col = "\033[34m"; //blue
	const char* red_col = "\033[31m"; //red
	const char* reset_col = "\033[0m"; //standart
	//const char* col = "\033[36m"; // cyan
	const char* col1 = "\033[33m"; // yellow
	const char* col2 = "\033[35m"; // magenta


	mx_bubble_list_sort(spisok);
	//struct dirent *entry;
	struct stat file_statistics;
    
    for (t_list *i = spisok; i != NULL; i = i->next) {
    	//sprintf(buff, "%s/%s", path, i->data);
    	if (stat(i->data, &file_statistics) == 0){
   			if (mx_strcmp(i->data, "Makefile") == 0) {
    			mx_printstr(i->data);
                mx_printstr("  "); 
    		}
            else if(S_ISDIR(file_statistics.st_mode)) {
            	write(STDOUT_FILENO, blue_col, 5);
            	write(STDOUT_FILENO, i->data, mx_strlen(i->data));
            	write(STDOUT_FILENO, reset_col, 4);
            	mx_printstr("  "); 
            }
            else if (S_ISREG(file_statistics.st_mode)) {
            	write(STDOUT_FILENO, red_col, 5);
            	write(STDOUT_FILENO, i->data, mx_strlen(i->data));
            	write(STDOUT_FILENO, reset_col, 4);
            	mx_printstr("  "); 
            }
            else if (S_ISBLK(file_statistics.st_mode) || S_ISCHR(file_statistics.st_mode)) {
            	write(STDOUT_FILENO, col1, 5);
            	write(STDOUT_FILENO, i->data, mx_strlen(i->data));
            	write(STDOUT_FILENO, reset_col, 4);
            	mx_printstr("  "); 
            }
            else if (S_ISFIFO(file_statistics.st_mode)) {
            	write(STDOUT_FILENO, col1, 5);
            	write(STDOUT_FILENO, i->data, mx_strlen(i->data));
            	write(STDOUT_FILENO, reset_col, 4);
            	mx_printstr("  "); 
            }
            else if (S_ISSOCK(file_statistics.st_mode)) {
            	write(STDOUT_FILENO, col2, 5);
            	write(STDOUT_FILENO, i->data, mx_strlen(i->data));
            	write(STDOUT_FILENO, reset_col, 4);
            	mx_printstr("  "); 
            }
            else {
                mx_printstr(i->data);
                mx_printstr("  "); 
            }
    	}
    }
    mx_printchar('\n');
}

