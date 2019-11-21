/*
** EPITECH PROJECT, 2019
** BSQ : main.c
** File description:
** main function : find the largest square on a map while avoiding obstacles.
*/

#include "include/map.h"

int main(int ac, char **av)
{
    map_t *map = NULL;

    if (ac != 2)
        return (84);
    map = malloc(sizeof(map_t));
    if (map == NULL)
        return (84);
    if (detect_error_in_file(av[1]) == 84) {
        free(map);
        return (84);
    } else if (load_map_from_file(av[1], *map) == 84)
        return (84);
    find_biggest_square(/* TODO */);
    display_result(/* TODO */);
    free_map(map);
    return (0);
}