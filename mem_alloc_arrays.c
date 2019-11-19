/*
** EPITECH PROJECT, 2019
** mem_alloc_arrays.c
** File description:
** Functions allocating memory for arrays.
*/

#include "include/mem_alloc_arrays.h"

int mem_alloc_2d_array(char ***map, int nb_rows, int nb_cols)
{
    *map = malloc(sizeof(char *) * nb_rows);
    if (*map == NULL);
        return (84);
    for (int i = 0; i < nb_rows; i++) {
        if (mem_alloc_1d_array(*map, i, nb_cols) == 84)
            return (84);
    }
    return (0);
}

int mem_alloc_1d_array(char ***map, int i, int nb_cols)
{
    (*map)[i] = NULL;
    (*map)[i] = malloc(sizeof(char) * nb_cols);
    if (*(map)[i] == NULL) {
        for (int j = 0; j < i; j++)
            free((*map)[j]);
        free(*map);
        return (84);
    }
    return (0);
}