/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Handles tetriminos' moves.
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

void set_move(game_data_t *gd, config_t config)
{
    gd->current_move.pos_x = config.map_width / 2;
    gd->current_move.pos_y = 0;
    gd->current_move.rotation = 0;
    gd->current_move.tetrimino = gd->next;
    gd->next = rand() % (config.tlist_size + 1);
}