#include "uls.h"

void ls_input_parser(int argc, char **argv, flags_t *flag, format_t *format) {
    int count_flags = 0;
    for (int i = 1; i < argc; i++)
        if (argv[i][0] == '-' && mx_strlen(argv[i]) != 1) {
            count_flags++;
            if (argv[i][1] == '-')
                break;
        }
        else
            break;
    if (count_flags > 0)
        flag_detector(count_flags , argc, argv, flag);
    file_dir_detector(count_flags, argc, argv, format);  
}
