#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <pwd.h>

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
    char **dirs;             /* NULL-terminated 2d arr with names of DIRECTORIES from output */
    int dirs_num;             /* number of dirs in dirs array */
    char **files;            /* NULL-terminated 2d arr with names of FILES from output */
    int files_num;           /* number of files in files array */ 
    char **no_file_dir;      /* NULL-terminated 2d arr with names of DIR/FILES that don't exist */
    int no_fd_num;          /* number of non files of dirs in no_file_dir array */ 
}              start_t;


typedef struct print_format {
    bool standart;           /* true - print output to terminal in lines when, no -l, -n, -o, -g, -1, or -m flags*/
    bool long_format;        /* true if -l, -n, -o, -g */
    bool one_per_line;       /* true if -1 */
    bool with_commas;        /* true if -m */
    bool print_in_terminal;  /* true - no "| cat" or other options while start */
}              format_t;

typedef struct data_storage {
    char *name;
    long long blok;
    unsigned long long ind_num;
    long long size;
    long date_m;
    char type;
    char *rights;
    char plus_or_at;
    unsigned short link_num;
    char *user_id;
    char *group_id;
}              data_t;

typedef struct biggest_len {
    short b_namelen;
    short b_blok;
    short b_ind_num;
    short b_size;
    short b_user_id;
    short b_group_id;
}              biggest_t;

void flags_init(flags_t *flag);
void mem_free(flags_t *flag);
void input_parser(int argc, char **argv, flags_t *flag, format_t *format, start_t *start_data);
void flag_detector(int count_flags, int argc, char **argv, flags_t *flag);
void file_dir_detector(int count_flags, int argc, char **argv, format_t *format, start_t *start_data);
void format_detector(format_t *format, flags_t *flag, start_t *start_data);
void data_collector(format_t *format, flags_t *flag, start_t *start_data, data_t ****data);
void get_data(data_t *data, flags_t *flag, format_t *format, char *dir_name);

void err_ill_option(char c, flags_t *flag);
void format_init(format_t *format);

// void free_mem(flags_t *flag);

#endif
