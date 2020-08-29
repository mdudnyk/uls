#include "uls.h"

int main(int argc, char **argv) {
    flags_t *flag = malloc(sizeof(flags_t));
    format_t *format = malloc(sizeof(format_t));
    start_t *start_data = malloc(sizeof(start_t));
    data_t ****data = malloc(sizeof(data_t***) * 2);

    flags_init(flag);
    format_init(format);
    input_parser(argc, argv, flag, format, start_data);
    format_detector(format, flag, start_data);
    data_collector(format, flag, start_data, data);

    // printf("dirs - %d, files - %d, no files - %d", start_data->dirs_num, start_data->files_num, start_data->no_fd_num);
    for (int j = 0; j < start_data->dirs_num; j++) {
        for (int i = 0; data[1][j][i] != NULL; i++) {
            printf("%s  ", data[1][j][i]->name);
        }
        printf("\n");
    }
    // mem_free(flag);
    // system("leaks uls");
}
