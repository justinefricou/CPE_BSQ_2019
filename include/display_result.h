/*
** EPITECH PROJECT, 2019
** BSQ : display_result.h
** File description:
** Displays the map with 'X's where the biggest square is located. (header)
*/

#ifndef DEF_DISPLAY_RESULT
#define DEF_DISPLAY_RESULT

#include <unistd.h>
#include "map.h"
#include "square.h"

void display_result(map_t *map, square *biggest_square);
void display_character(map_t *map, int row, int col, square *biggest_sqr);
void my_putchar(char c);

#endif // DEF_DISPLAY_RESULT