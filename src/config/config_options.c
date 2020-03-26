/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Configuration of options (map size, debug mode, hiding next tetrimino, etc).
*/

#include "tetris.h"

int config_size(config_t *config)
{
    char *pointer = optarg;

    if (!my_is_int(&pointer, ','))
        return (84);
    if (*pointer != ',')
        return (84);
    pointer++;
    if (!my_is_int(&pointer, ' '))
        return (84);
    pointer = optarg;
    config->map_height = get_next_nbr(&pointer, ',');
    pointer++;
    config->map_width = get_next_nbr(&pointer, ' ');
    if (config->map_height <= 0 || config->map_width <= 0)
        return (84);
    check_tetriminos_sizes(config);
    return (0);
}

int config_level(config_t *config)
{
    char *pointer = optarg;

    if (!my_is_int(&pointer, ' '))
        return (84);
    pointer = optarg;
    config->level = get_next_nbr(&pointer, ' ');
    if (config->level <= 0)
        return (84);
    return (0);
}

int config_next(config_t *config)
{
    config->hide_next = 1;
    return (0);
}

int config_debug(config_t *config)
{
    config->debug_mode = 1;
    return (0);
}