#include "../inc/uls.h"


static void mx_format_error(void) {
    mx_printerr("usage: uls [-l] [file...]\n");
    exit(1);
}

//a my berem tol`ko poslednuu chast directorii ili vsu?
void mx_uncreated_file(char* oshibka) {
    mx_printerr("uls: ");
    mx_printstr(oshibka);
    mx_printerr(": No such file or directory");
    mx_printchar('\n');
    exit(1);
}

void mx_uls_errors_checker(int argc) {
    if (argc < 1)
       mx_format_error();
}


