/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Parsing of tetriminos' configuration files.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fae.h"
#include "tetris.h"
#include "ncurses.h"
#include "game.h"

void move_left(config_t *config, game_data_t *gd)
{
    if (gd->current_move.pos_x > 0)
        gd->current_move.pos_x--;
}

void move_right(config_t *config, game_data_t *gd)
{
    tetrimino_t *tetri = get_tetro_by_id(*config, gd->current_move.tetrimino);
    int max = config->map_width - tetri->width;

    if (gd->current_move.pos_x < max)
        gd->current_move.pos_x++;
}