/*
** EPITECH PROJECT, 2019
** BSQ : error_detection.c
** File description:
** Functions used to detect errors in the file.
*/

#include "include/error_detection.h"

int detect_error_in_file(char *filepath)
{
    int file_descr = 0;

    file_descr = open(filepath, O_RDONLY);
    if (file_descr == -1)
        return (84);
    if (check_first_line(file_descr) == 84 || check_map(file_descr) == 84) {
        close(file_descr);
        return (84);
    }
    close(file_descr);
    return (0);
}

int check_first_line(int file_descr)
{
    int read_size = 0;
    char buffer[2] = {0};

    read_size = read(file_descr, buffer, 1);
    if (read_size <= 0)
        return (84);
    if (!is_digit(buffer[0]) && buffer[0] != '+')
        return (84);
    for ( ; buffer[0] != '\n'; ) {
        read_size = read(file_descr, buffer, 1);
        if (read_size <= 0)
            return (84);
        if (!is_digit(buffer[0]) && buffer[0] != '\n')
            return (84);
    }
    return (0);
}

int check_map(int file_descr)
{
    int read_size = 1, size_curr_line = 0, size_last_line = 0;
    char buff[2] = {0};

    for ( ; read_size > 0; ) {
        read_size = read(file_descr, buff, 1);
        if (read_size < 0)
            return (84);
        if (buff[0] != '.' && buff[0] != 'o' && buff[0] != '\n')
            return (84);
        if (handle_lines_sizes(&size_curr_line, &size_last_line, buff[0]) == 84)
            return (84);
    }
    if (buff[0] != '\n')
        return (84);
    return (0);
}

int is_digit(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

int handle_lines_sizes(int *curr_size, int *last_size, char buffer)
{
    if (buffer == '\n') {
        if (*last_size == 0 && *curr_size == 0)
            return (84);
        if (*last_size != *curr_size && *last_size != 0 && *curr_size != 0)
            return (84);
        *last_size = *curr_size;
        *curr_size = 0;
    } else
        (*curr_size)++;
}