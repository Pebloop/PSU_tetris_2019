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

static void display_border_line(config_t config, int i)
{
    for (int x = 1; x <= config.map_width; x++)
        mvprintw(i, x, "-");
    mvprintw(i, 0, "*");
    mvprintw(i, config.map_width + 1, "*");
}

static void display_bloc(config_t config, game_data_t *gd, int i, int x)
{
    attron(COLOR_PAIR(gd->board[i][x]));
    mvprintw(i + 1, x + 1, " ");
    attroff(COLOR_PAIR(gd->board[i][x]));
}

void display_line(config_t config, game_data_t *gd, int i)
{
    if (i == 0 || i == config.map_height + 1)
        display_border_line(config, i);
    else {
        mvaddch(i, 0, '|');
        mvaddch(i, config.map_width + 1, '|');
        for (int x = 0; x < config.map_width; x++)
            display_bloc(config, gd, i - 1, x);
    }
}
