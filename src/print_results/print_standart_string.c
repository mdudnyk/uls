#include "uls.h"

static char *fill_string(char *string, int string_width, short field_len, char *data_field, bool right_side) {
    int i = string_width - 1;
    for ( ; string[i - 1] == ' ' && i > 0; i--) {}
    if (i != 0)
        i += 1;
    if (right_side)
        i = i + field_len - mx_strlen(data_field);
    for (int j = 0; data_field[j]; j++) {
        string[i++] = data_field[j];  
    }
    return string;
}

void print_standart_string(data_t **data, flags_t *flag, largest_t *largest, int console_size, int col_width) {
    char *string = mx_strnew(col_width);
    int j = 0;
    for (int i = 0; data[i] != NULL; i++) {
        mx_memset(string, ' ', col_width);
        if (flag->i) {
            string = fill_string(string, col_width, largest->indnumlen, data[i]->ind_num_ch, true);
        }
        if (flag->s) {
            string = fill_string(string, col_width, largest->bloknumlen, data[i]->block_ch, true);
        }
        string = fill_string(string, col_width, largest->namelen, data[i]->name, false);
        if (flag->F) {
            for (j = col_width - 1; string[j - 1] == ' ' && i > 0; j--) {}
            switch (data[i]->type) {
                case 'd': string[j] = '/'; break;
                case 'l': string[j] = '@'; break;
                case '-': if (data[i]->rights[2] == 'x') string[j] = '*'; break;
            }
        }
        mx_printstr(string);
    }
    free(string);
}
