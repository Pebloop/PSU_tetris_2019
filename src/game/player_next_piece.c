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

static lock_piece(tetrimino_t *current,
    game_data_t *gd, int y, int x)
{
    vector_t pixel = calcul_rotation(current, gd, x, y);

    if (current->shape[y][x])
        gd->board[gd->current_move.pos_y + pixel.y][gd->current_move.pos_x + pixel.x] =
            current->color;
}

static int kill_check_line(config_t *config, game_data_t *gd, int y)
{
    for (int x = 0; x < config->map_width; x++) {
        if (!gd->board[y][x])
            return 0;
    }
    return 1;
}

static void kill_down(config_t *config, game_data_t *gd, int y)
{
    for (y = y - 1; y >= 0; y--) {
        for (int x = 0; x < config->map_width; x++) {
            gd->board[y + 1][x] = gd->board[y][x];
        }
    }
    gd->lines++;
}

static void kill_lines(config_t *config, game_data_t *gd){
    int lines = 0;

    for (int y = config->map_height - 1; y >= 0; y--) {
        if (kill_check_line(config, gd, y)) {
            kill_down(config, gd, y);
            lines++;
        }
    }
    gd->score += calcul_score(lines, 50) * config->level;
    config->level = gd->lines / 10 + 1;
}

void player_next_piece(config_t *config, game_data_t *gd)
{
    tetrimino_t *current = get_tetro_by_id(*config,
        gd->current_move.tetrimino);

    for (int y = 0; y < current->height; y++) {
        for (int x = 0; x < current->width; x++) {
            lock_piece(current, gd, y, x);
        }
    }
    kill_lines(config, gd);
    set_move(gd, *config);
    if (test_collision(*config, gd))
        gd->lose = 1;
    else
        gd->score += 10 * config->level;
    gd->easy_spin = 0;
}