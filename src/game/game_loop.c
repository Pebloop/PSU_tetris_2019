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
        return 0;
    }
    return 1;
}

void manage_input(config_t *config, game_data_t *gd, int input)
{
    (input == config->key.move_left) ? move_left(config, gd) : 0;
    (input == config->key.move_right) ? move_right(config, gd) : 0;
    if (input == config->key.rotate)
        gd->current_move.rotation++;
    if (gd->current_move.rotation > 3)
        gd->current_move.rotation = 0;
}

int game_loop(config_t *config, game_data_t *gd)
{
    int input = 0;

    display_error_size_screen(config);
    diplay_game(*config, gd);
    refresh();
    input = getch();
    if (input == config->key.quit)
        return 1;
    manage_input(config, gd, input);
    return 0;
}