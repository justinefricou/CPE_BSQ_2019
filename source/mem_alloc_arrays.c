/*
** EPITECH PROJECT, 2019
** mem_alloc_arrays.c
** File description:
** Functions allocating memory for arrays.
*/

#include "mem_alloc_arrays.h"

int mem_alloc_2d_array_to_map(map_t *map)
{
    map->array = malloc(sizeof(char *) * map->rows);
    if (map->array == NULL)
        return (84);
    for (int i = 0; i < map->rows; i++) {
        if (mem_alloc_1d_array_to_map(map, i) == 84)
            return (84);
    }
    return (0);
}

int mem_alloc_1d_array_to_map(map_t *map, int i)
{
    (map->array)[i] = NULL;
    (map->array)[i] = malloc(sizeof(char) * map->cols);
    if ((map->array)[i] == NULL) {
        for (int j = 0; j < i; j++)
            free((map->array)[j]);
        free(map->array);
        return (84);
    }
    return (0);
}