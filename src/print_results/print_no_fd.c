#include "uls.h"

void print_no_fd(start_t *start_data) {
    for (int i = 0; i < start_data->no_fd_num; i++) {
        mx_printerr("uls: ");
        perror(start_data->no_file_dir[i]);
    }
}
