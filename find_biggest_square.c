/*
** EPITECH PROJECT, 2019
** BSQ : find_biggest_square.c
** File description:
** Find the largest square on a map while avoiding obstacles.
*/

#include "include/find_biggest_square.h"

int find_biggest_square_in_map(map_t *map, square *biggest_square)
{
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            get_bsq_from_location(map, i, j, biggest_square);
        }
    }
    if (biggest_square->size == 0)
        return (84);
    return (0);
}

void get_bsq_from_location(map_t *map, int row, int col, square *biggest_sqr)
{
    int biggest_size = biggest_sqr->size;

    while (is_square_of_size(map, row, col, biggest_size + 1))
        biggest_size++;
    if (biggest_size > biggest_sqr->size) {
        biggest_sqr->size = biggest_size;
        biggest_sqr->x = row;
        biggest_sqr->y = col;
    }
}

int is_square_of_size(map_t *map, int row, int col, int size)
{
    int i = 0;

    for ( ; row < map->rows && i < size; row++, i++) {
        if (!is_line(size, &(((map->array)[row])[col]), map->cols - col))
            return (0);
    }
    if (i != size)
        return (0);
    return (1);
}

int is_line(int size, char *line, int line_length)
{
    int i = 0;

    for ( ; i < line_length && i < size; i++) {
        if (line[i] != '.')
            return (0);
    }
    if (i != size)
        return (0);
    return (1);
}