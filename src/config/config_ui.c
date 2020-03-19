/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Configuration of pause and quit keys.
*/

#include <unistd.h>
#include "tetris.h"

int config_quit(config_t *config)
{
    config->key.quit = *optarg;
    return (0);
}

int config_pause(config_t *config)
{
    config->key.pause = *optarg;
    return (0);
}