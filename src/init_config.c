/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Main function
*/

#include "tetris.h"
#include "ncurses.h"

void init_config(config_t *config)
{
    config->tetri_list = NULL;
    config->level = 1;
    config->hide_next = 0;
    config->debug_mode = 0;
    config->map_width = 10;
    config->map_height = 20;
    config->key_move_left = KEY_LEFT;
    config->key_move_right = KEY_RIGHT;
    config->key_rotate = KEY_UP;
    config->key_drop = KEY_DOWN;
    config->key_pause = ' ';
    config->key_quit = 'q';
}