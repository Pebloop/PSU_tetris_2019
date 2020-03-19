/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Configuration of control keys (move to the left/to the right, rotate, drop).
*/

#include "tetris.h"

int config_left(config_t *config)
{
    config->key.move_left = *optarg;
    return (0);
}

int config_right(config_t *config)
{
    config->key.move_right = *optarg;
    return (0);
}

int config_rotate(config_t *config)
{
    config->key.rotate = *optarg;
    return (0);
}

int config_drop(config_t *config)
{
    config->key.drop = *optarg;
    return (0);
}