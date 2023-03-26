#include "../inc/uls.h"


static void mx_format_error(void) {
    mx_printerr("usage: uls [-l] [file...]\n");
    exit(1);
}


void mx_uncreated_file(char* oshibka) {
    mx_printerr("uls: ");
    mx_printerr(oshibka);
    mx_printerr(": No such file or directory\n");
}

void mx_uls_errors_checker(int argc) {
    if (argc < 1)
       mx_format_error();
}


