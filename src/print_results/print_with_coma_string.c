#include "uls.h"

static int field_len(int len_counter, largest_t *largest, int name_len, flags_t *flag) {
    if (flag->i)
        len_counter += largest->indnumlen + 1;
    if (flag->s)
        len_counter += largest->bloknumlen + 1;
    if (flag->F)
        len_counter++; 
    len_counter += name_len + 2;
    return len_counter;
}

static char *field_maker(int size) {
    char *str = mx_strnew(size);
    mx_memset(str, ' ', size);
    return str;
}

static char *field_filler(char *field, char *data, int size, bool right_side) {
    int start = 0;

    if (right_side)
        start = size - mx_strlen(data);
    for (int i = 0; data[i] != '\0'; i++)
        field[start++] = data[i];  
    return field;
}

static void field_printer(char *field, short spaces_after) {
    mx_printstr(field);
    for (int i = 0; i < spaces_after; i++)
        mx_printchar(' ');
}

static void print_processor(short len, char *data_field, short spaces_after, bool right_side) {
    char *field = field_maker(len);
    field = field_filler(field, data_field, len, right_side);
    field_printer(field, spaces_after);
    free(field);
}

void print_with_coma_string(data_t **data, flags_t *flag, largest_t *largest, int console_size) {
    int len_counter = 0;

    for (int i = 0; data[i] != NULL; i++) {
        len_counter = field_len(len_counter, largest, mx_strlen(data[i]->name), flag);
        if ((len_counter + 1) > console_size) {
            mx_printchar('\n');
            len_counter = 0;
            len_counter = field_len(len_counter, largest, mx_strlen(data[i]->name), flag);
        }
        if (flag->i)
            print_processor(largest->indnumlen, data[i]->ind_num_ch, 1, true);
        if (flag->s)
            print_processor(largest->bloknumlen, data[i]->block_ch, 1, true);
        mx_printstr(data[i]->name);
        if (flag->F)
            switch (data[i]->type) {
                case 'd': mx_printchar('/'); break;
                case 'l': mx_printchar('@'); break;
                case '-': if (data[i]->rights[2] == 'x') mx_printchar('*'); break;
            }
        if (data[i + 1] != NULL)
            mx_printstr(", ");
    }
}
