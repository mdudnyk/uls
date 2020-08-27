#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <grp.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>

typedef struct flags {
    char *all_flags;
    bool A;
    bool F;
    bool S;
    bool a;
    bool d;
    bool g;
    bool h;
    bool i;
    bool l;
    bool n;
    bool m;
    bool o;
    bool p;
    bool r;
    bool s;
    bool t;
    bool one;
}              flags_t;

typedef struct start_data_list {
    char **dirs;
    char **files;
    char **no_file_dir;
}              start_t;


typedef struct print_format {
    bool standart;           /* true - print output to terminal in lines when, no -l, -n, -o, -g, -1, or -m flags*/
    bool long_format;        /* true if -l, -n, -o, -g */
    bool one_per_line;       /* true if -1 */
    bool with_commas;        /* true if -m */
    bool print_in_terminal;  /* true - no "| cat" or other options while start */
}              format_t;

void flags_init(flags_t *flag);
void mem_free(flags_t *flag);
void ls_input_parser(int argc, char **argv, flags_t *flag, format_t *format, start_t *start_data);
void flag_detector(int count_flags, int argc, char **argv, flags_t *flag);
void file_dir_detector(int count_flags, int argc, char **argv, format_t *format, start_t *start_data);

void err_ill_option(char c, flags_t *flag);
void format_init(format_t *format);

// void free_mem(flags_t *flag);

#endif
