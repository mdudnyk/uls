#include "uls.h"

int main(int argc, char **argv) {
    flags_t *flag = malloc(sizeof(flags_t));
    format_t *format = malloc(sizeof(format_t));
    start_t *start_data = malloc(sizeof(start_t));

    flags_init(flag);
    format_init(format);
    input_parser(argc, argv, flag, format, start_data);
    format_detector(format, flag, start_data);
    data_collector(format, flag, start_data);

    if (format->standart && format->print_in_terminal) {
        //your function
    }
    // mem_free(flag);
    // system("leaks uls");
}
