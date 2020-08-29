#include "uls.h"

static data_t **if_d_flag(flags_t *flag, data_t **data, char *dir_name) {
    DIR *d = opendir(dir_name);
    struct dirent *directory;
    struct stat sb;

    data = malloc(sizeof(data_t*) * 2);
    data[0] = malloc(sizeof(data_t));
    data[0]->name = malloc(sizeof(char) * mx_strlen(dir_name));
    data[0]->name = mx_strcpy(data[0]->name, dir_name);
    data[1] = NULL;
    return data;
}

static data_t **if_A_flag(flags_t *flag, data_t **data, char *dir_name) {
    DIR *d = opendir(dir_name);
    struct dirent *directory;
    struct stat sb;
    int counter = 1;
    int i = 0;
    

    while ((directory = readdir(d)) != NULL)
        counter++;
    closedir(d);
    d = opendir(dir_name);
    data = malloc(sizeof(data_t*) * (counter - 2));
    for ( ; i < 2; i++)
        readdir(d);  
    for (i = 0; (directory = readdir(d)) != NULL; i++) {
        data[i] = malloc(sizeof(data_t));
        data[i]->name = malloc(sizeof(char) * directory->d_namlen);
        data[i]->name = mx_strcpy(data[i]->name, directory->d_name);
    }
    data[i] = NULL;
    return data;
}

static data_t **if_a_flag(flags_t *flag, data_t **data, char *dir_name) {
    DIR *d = opendir(dir_name);
    struct dirent *directory;
    struct stat sb;
    int counter = 1;
    int i = 0;

    while ((directory = readdir(d)) != NULL)
        counter++;
    closedir(d);
    d = opendir(dir_name);
    data = malloc(sizeof(data_t*) * counter);
    while ((directory = readdir(d)) != NULL) {
        data[i] = malloc(sizeof(data_t));
        data[i]->name = malloc(sizeof(char) * directory->d_namlen);
        data[i]->name = mx_strcpy(data[i]->name, directory->d_name);
        i++;
    }
    
    data[i] = NULL;
    return data;
}

static data_t **if_default_flag(flags_t *flag, data_t **data, char *dir_name) {
    DIR *d = opendir(dir_name);
    struct dirent *directory;
    struct stat sb;
    int counter = 1;
    int i = 0;

    while ((directory = readdir(d)) != NULL) {
        if (directory->d_name[0] != '.')
            counter++;
    }
    closedir(d);
    d = opendir(dir_name);
    data = malloc(sizeof(data_t*) * counter);
    while ((directory = readdir(d)) != NULL) {
         if (directory->d_name[0] != '.') {
            data[i] = malloc(sizeof(data_t));
            data[i]->name = malloc(sizeof(char) * directory->d_namlen);
            data[i]->name = mx_strcpy(data[i]->name, directory->d_name);
            i++;
         }
    }
    data[i] = NULL;
    return data;
}

void data_collector(format_t *format, flags_t *flag, start_t *start_data, data_t ****data) {
    if (start_data->files_num > 0)
        data[0] = malloc(sizeof(data_t**) * (start_data->files_num));
    else 
        data[0] = NULL;

    data[1] = malloc(sizeof(data_t**) * (start_data->dirs_num));
    data[1][0]= NULL;
    for (int i = 0; i < start_data->dirs_num; i++) {
        if (flag->d == true) {
            data[1][i] = if_d_flag(flag, data[1][i], start_data->dirs[i]);
        }
        else 
            if (flag->A == true) {
                data[1][i] = if_A_flag(flag, data[1][i], start_data->dirs[i]);
            }
            else 
                if (flag->a == true) {
                    data[1][i] = if_a_flag(flag, data[1][i], start_data->dirs[i]);
                }
                else
                    data[1][i] = if_default_flag(flag, data[1][i], start_data->dirs[i]);
    }   
}
