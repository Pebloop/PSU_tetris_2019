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

void move_left(config_t *config, game_data_t *gd)
{
    gd->current_move.pos_x--;
    if (test_collision(*config, gd)) {
        gd->current_move.pos_x++;
    } else
        easy_spin_update(gd);
}

void move_right(config_t *config, game_data_t *gd)
{
    gd->current_move.pos_x++;
    if (test_collision(*config, gd)) {
        gd->current_move.pos_x--;
    } else
        easy_spin_update(gd);
}

void move_drop(config_t *config, game_data_t *gd)
{
    gd->turn.current = 2;
}

void rotate(config_t *config, game_data_t *gd)
{
    int tmp = gd->current_move.rotation;

    gd->current_move.rotation++;
    if (gd->current_move.rotation > 3)
        gd->current_move.rotation = 0;
    if (test_collision(*config, gd))
        gd->current_move.rotation = tmp;
    easy_spin_update(gd);
}

void game_pause()
{
    nodelay(stdscr, FALSE);
    getch();
    nodelay(stdscr, TRUE);
}