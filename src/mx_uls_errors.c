#include "../inc/uls.h"


static void mx_directory_check_error(int argc, char* argv[], int file) {
    if (file <= 0) {
        int index = argc - 1;
        mx_printerr("uls: ");
        mx_printerr(argv[index]);
        mx_printerr(" No such file or directory\n");
        close(file);
        exit(1);
    }
}

static void mx_format_error(void) {
    mx_printerr("usage: uls [-l] [file...]\n");
    exit(1);
}

void mx_uls_errors_checker(int argc, char* argv[]) {
    if (argc < 1)
       mx_format_error();
    int file = open(argv[1], O_RDONLY);
    if (argc > 1)
        mx_directory_check_error(argc, argv, file);
}


