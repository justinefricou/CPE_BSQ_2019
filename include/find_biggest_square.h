/*
** EPITECH PROJECT, 2019
** BSQ : find_biggest_square.h
** File description:
** Find the largest square on a map while avoiding obstacles. (header)
*/

#ifndef DEF_FIND_BIGGEST_SQUARE
#define DEF_FIND_BIGGEST_SQUARE

#include "map.h"
#include "square.h"

int find_biggest_square_in_map(map_t *map, square *biggest_square);
void get_bsq_from_location(map_t *map, int row, int col, square *biggest_sqr);
int is_square_of_size(map_t *map, int row, int col, int size);
int is_line(int size, char *line, int line_length);

#endif // DEF_FIND_BIGGEST_SQUARE