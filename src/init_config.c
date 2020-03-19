/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Initializes the configuration (level, keys, options, etc).
*/

#include "tetris.h"
#include "ncurses.h"

int init_config(config_t *config)
{
    config->tetri_list = NULL;

    if (get_tetriminos_list(&(config->tetri_list)) == 84)
        return (84);
    config->tlist_size = 0;
    for (tetrimino_t *t = config->tetri_list; t; t = t->next)
        config->tlist_size += 1;
    config->level = 1;
    config->hide_next = 0;
    config->debug_mode = 0;
    config->map_width = 10;
    config->map_height = 20;
    config->key.move_left = KEY_LEFT;
    config->key.move_right = KEY_RIGHT;
    config->key.rotate = KEY_UP;
    config->key.drop = KEY_DOWN;
    config->key.pause = ' ';
    config->key.quit = 'q';
    return 0;
}