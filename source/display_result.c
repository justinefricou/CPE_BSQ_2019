/*
** EPITECH PROJECT, 2019
** BSQ : display_result.c
** File description:
** Displays the map with 'X's where the biggest square is located.
*/

#include "include/display_result.h"

void display_result(map_t *map, square *biggest_square)
{
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++)
            display_character(map, i, j, biggest_square);
        my_putchar('\n');
    }
}

void display_character(map_t *map, int row, int col, square *biggest_sqr)
{
    if (biggest_sqr->x <= row && row < biggest_sqr->x + biggest_sqr->size) {
        if (biggest_sqr->y <= col && col < biggest_sqr->y + biggest_sqr->size)
            my_putchar('x');
        else
            my_putchar((map->array)[row][col]);
    } else
        my_putchar((map->array)[row][col]);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}