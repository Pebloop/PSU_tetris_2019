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

int display_error_size_screen(config_t *config)
{
    int x = 0;
    int y = 0;
    int min_x = config->map_width + 2;
    int min_y = config->map_height + 2;

    getmaxyx(stdscr, y, x);
    if (x < min_x || y < min_y) {
        while (x < min_x || y < min_y) {
            erase();
            getmaxyx(stdscr, y, x);
            mvprintw(y / 2, x / 2 - 13, "Please, enlarge the screen");
            refresh();
        }
        erase();
        return 0;
    }
    return 1;
}

void manage_input(config_t *config, game_data_t *gd, int input)
{
    (input == config->key.move_left) ? move_left(config, gd) : 0;
    (input == config->key.move_right) ? move_right(config, gd) : 0;
    (input == config->key.drop) ? move_drop(config, gd) : 0;
    (input == config->key.rotate) ? rotate(config, gd) : 0;
    (input == config->key.pause) ? game_pause() : 0;
}

int end_turn(config_t *config, game_data_t *gd)
{
    gd->current_move.pos_y++;
    if (test_collision(*config, gd)) {
        gd->current_move.pos_y--;
        player_next_piece(config, gd);
    }
    clock_init(&(gd->turn));
}

int block_data(config_t *config, game_data_t *gd)
{
    config->level = (config->level > 20) ? 20 : config->level;
    gd->score = (gd->score > 999999) ? 999999 : gd->score;
    gd->timer.current = (gd->score > 60 * 99) ? 60 * 99 : gd->score;
}

int game_loop(config_t *config, game_data_t *gd)
{
    int input = 0;

    clock_update(&(gd->timer));
    clock_update(&(gd->turn));
    display_error_size_screen(config);
    diplay_game(*config, gd);
    refresh();
    input = getch();
    if (input == config->key.quit)
        return 1;
    manage_input(config, gd, input);
    if (gd->turn.current > 1.0 / config->level)
        end_turn(config, gd);
    block_data(config, gd);
    return gd->lose;
}