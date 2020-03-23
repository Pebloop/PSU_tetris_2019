/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Configuration of control keys (move to the left/to the right, rotate, drop).
*/

#include "tetris.h"

int config_left(config_t *config)
{
    config->key.move_left = config_get_key(optarg);
    if (config->key.move_left == -1)
        return (84);
    return (0);
}

int config_right(config_t *config)
{
    config->key.move_right = config_get_key(optarg);
    if (config->key.move_right == -1)
        return (84);
    return (0);
}

int config_rotate(config_t *config)
{
    config->key.rotate = config_get_key(optarg);
    if (config->key.rotate == -1)
        return (84);
    return (0);
}

int config_drop(config_t *config)
{
    config->key.drop = config_get_key(optarg);
    if (config->key.drop == -1)
        return (84);
    return (0);
}