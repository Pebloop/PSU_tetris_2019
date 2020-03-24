/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Displays the game.
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

static void display_rotated(game_data_t *gd, int x, int y)
{
    mvprintw(gd->current_move.pos_y + 1 + y,
            gd->current_move.pos_x + 1 + x, " ");
}

static void display_player_tetromino(tetrimino_t *current,
    game_data_t *gd, int y, int x)
{
    vector_t pixel = calcul_rotation(current, gd, x, y);

    if (current->shape[y][x]) {
        attron(COLOR_PAIR(current->color));
        display_rotated(gd, pixel.x, pixel.y);
        attroff(COLOR_PAIR(current->color));
    }
}

void display_player(config_t config, game_data_t *gd)
{
    tetrimino_t *current = get_tetro_by_id(config, gd->current_move.tetrimino);

    for (int y = 0; y < current->height; y++) {
        for (int x = 0; x < current->width; x++)
            display_player_tetromino(current, gd, y, x);
    }
}

void diplay_game(config_t config, game_data_t *gd)
{
    for (int i = 0; i <= config.map_height + 1; i++) {
        display_line(config, gd, i);
    }
    display_player(config, gd);
    if (!config.hide_next)
        display_next(config, gd);
    display_score(config, gd);
}