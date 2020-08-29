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
    printf("files - %d, dirs - %d, no_fd - %d\n", start_data->files_num, start_data->dirs_num, start_data->no_fd_num);
    if (format->long_format) {
        for (int i = 0; i < start_data->files_num; i++) {
            printf("%c", data[0][i][0]->type);
            printf("%s", data[0][i][0]->rights);
            printf("%c ", data[0][i][0]->plus_or_at);
            printf("%d ", data[0][i][0]->link_num);
            printf("%s ", data[0][i][0]->user_id);
            printf("%s ", data[0][i][0]->group_id);
            printf("%llu ", data[0][i][0]->size);
            printf("%s\n", data[0][i][0]->name);
            printf("\n");
        }
        for (int j = 0; j < start_data->dirs_num; j++) {
            for (int i = 0; data[1][j][i] != NULL; i++) {
                printf("%c", data[1][j][i]->type);
                printf("%s", data[1][j][i]->rights);
                printf("%c ", data[1][j][i]->plus_or_at);
                printf("%d ", data[1][j][i]->link_num);
                printf("%s ", data[1][j][i]->user_id);
                printf("%s ", data[1][j][i]->group_id);
                printf("%llu ", data[1][j][i]->size);
                printf("%s\n", data[1][j][i]->name);
            }
            printf("\n");
        }
    }
    // mem_free(flag);
    // system("leaks uls");
}

