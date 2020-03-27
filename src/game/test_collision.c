/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Game loop.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "fae.h"
#include "tetris.h"
#include "ncurses.h"
#include "game.h"

static int try_bloc(config_t config, game_data_t *gd, int x, int y)
{
    tetrimino_t *current = get_tetro_by_id(config, gd->current_move.tetrimino);
    vector_t pixel = calcul_rotation(current, gd, x, y);

    if (!current->shape[y][x])
        return 0;
    if (gd->current_move.pos_y + pixel.y >= config.map_height
        || gd->current_move.pos_x + pixel.x >= config.map_width
        || gd->current_move.pos_x + pixel.x < 0
        || gd->board[gd->current_move.pos_y + pixel.y]\
        [gd->current_move.pos_x + pixel.x])
        return 1;
    return 0;
}

int test_collision(config_t config, game_data_t *gd)
{
    int collision = 0;
    tetrimino_t *current = get_tetro_by_id(config, gd->current_move.tetrimino);

    for (int y = 0; y < current->height; y++) {
        for (int x = 0; x < current->width; x++) {
            collision += try_bloc(config, gd, x, y);
        }
    }
    return collision;
}