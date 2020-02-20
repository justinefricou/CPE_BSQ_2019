/*
** EPITECH PROJECT, 2019
** map_initializing.c
** File description:
** Functions to initialize a map's array, width and height.
*/

#include "map_initializing.h"

int set_map_dimensions(char *filepath, map_t *map)
{
    int file_desc = 0;

    map->rows = 0;
    map->cols = 0;
    file_desc = open(filepath, O_RDONLY);
    if (file_desc == -1)
        return (84);
    if (get_number_from_line(file_desc, &(map->rows)) == 84 || map->rows <= 0) {
        close(file_desc);
        return (84);
    } else if (get_columns_nb_from_file(file_desc, &(map->cols)) == 84) {
        close(file_desc);
        return (84);
    }
    close(file_desc);
    return (0);
}

int get_number_from_line(int file_descr, int *nbr)
{
    int size_read = 0;
    char buffer[2] = {0};

    size_read = read(file_descr, buffer, 1);
    if (size_read == -1)
        return (84);
    if (buffer[0] != '+')
        *nbr = (*nbr) * 10 + (buffer[0] - 48);
    for ( ; size_read > 0 && buffer[0] != '\n'; ) {
        size_read = read(file_descr, buffer, 1);
        if (size_read == -1)
            return (84);
        if (buffer[0] != '\n' && size_read > 0)
            *nbr = (*nbr) * 10 + (buffer[0] - 48);
    }
    return (0);
}

int get_columns_nb_from_file(int file_descr, int *nbr)
{
    int size_read = 1;
    char buffer[2] = {0};

    for ( ; size_read > 0 && buffer[0] != '\n'; ) {
        size_read = read(file_descr, buffer, 1);
        if (size_read == -1)
            return (84);
        if (size_read > 0 && buffer[0] != '\n')
            (*nbr)++;
    }
    return (0);
}

int copy_file_in_map(int fd, map_t *map)
{
    int s_read = 1;
    char buffer[2] = {0};

    for ( ; buffer[0] != '\n'; ) {
        s_read = read(fd, buffer, 1);
        if (s_read == -1)
            return (84);
    }
    for (int i = 0; i < map->rows && s_read == 1; i++) {
        if (copy_line_in_arr(fd, map->cols, (map->array)[i], &s_read) == 84)
            return (84);
        s_read = read(fd, buffer, 1);
        if (s_read == -1)
            return (84);
        buffer[0] = 0;
    }
    return (0);
}

int copy_line_in_arr(int file_descr, int nb_cols, char *line, int *size_read)
{
    char buffer[2] = {0};
    for (int i = 0; i < nb_cols && *size_read == 1; i++) {
        *size_read = read(file_descr, buffer, 1);
        if (*size_read == -1)
            return (84);
        line[i] = buffer[0];
    }
    return (0);
}