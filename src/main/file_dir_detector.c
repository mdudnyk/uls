#include "uls.h"

void file_dir_detector(int count_flags, int argc, char **argv, format_t *format) {
    int i = count_flags;
    int j = 0;

    if (count_flags < argc - 1) {
        names_string = malloc(sizeof(char*) * (argc - i)); 
        for (i++ ; i < argc; i++, j++) {
            names_string[j] = mx_strnew(mx_strlen(argv[i]));
            names_string[j] = mx_strcpy(names_string[j], argv[i]);
        }
        names_string[j] = NULL;
    }
    else {
        names_string = malloc(sizeof(char*) * (2));
        names_string[0] = ".";
        names_string[1] = NULL;
    }
    // for (int i = 0; names_string[i] != NULL; i++) {
    //     mx_printstr(names_string[i]);
    //     mx_printchar(' ');
    // }
}
