#include "uls.h"

void format_init(format_t *format) {
    format->standart = true;
    format->long_format = false;
    format->one_per_line = false;
    format->with_commas = false;
    format->print_in_terminal = true;
}
