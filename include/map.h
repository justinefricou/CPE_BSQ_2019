/*
** EPITECH PROJECT, 2019
** map.h
** File description:
** Structure containing a 2d-array representing a map, and its length and width.
*/

#ifndef DEF_MAP
#define DEF_MAP

#include <stdlib.h>

typedef struct map {
    char **array;
    int rows;
    int cols;
} map_t;

void free_map(map_t map);

#endif // DEF_MAP