/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Configuration of pause and quit keys.
*/

#include <unistd.h>
#include "ncurses.h"
#include "tetris.h"

int config_quit(config_t *config)
{
    config->key.quit = config_get_key(optarg);
    if (config->key.quit == -1)
        return (84);
    return (0);
}

int config_pause(config_t *config)
{
    config->key.pause = config_get_key(optarg);
    if (config->key.pause == -1)
        return (84);
    return (0);
}

int config_get_key(char *str)
{
    if (str[1] == 0 && 7 <= str[0])
        return (*str);
    if (str[0] == '^' && str[1] == 'E' && str[2] == 'O') {
        switch (str[3]) {
        case 'A' :
            return (KEY_UP);
        case 'B' :
            return (KEY_DOWN);
        case 'C' :
            return (KEY_RIGHT);
        case 'D' :
            return (KEY_LEFT);
        }
    }
    return (-1);
}