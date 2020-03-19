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
#include "time.h"

static void start_ncurses(void)
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
    clear();
}

static void game_init(config_t config, game_data_t *gd)
{
    srand(clock());
    gd->board = malloc(sizeof(int *) * config.map_height);
    for (int i = 0; i < config.map_height; i++) {
        gd->board[i] = malloc(sizeof(int) * config.map_width);
        for (int x = 0; x < config.map_width; x++)
            gd->board[i][x] = 0;
    }
    set_move(gd, config);
    gd->lines = 0;
    gd->score = 0;
    gd->timer = 0;
}

static void end_curses(void)
{
    curs_set(TRUE);
    endwin();
}

int launch_game(config_t config)
{  
    game_data_t gd = {0};

    start_ncurses();
    game_init(config, &gd);
    while (!game_loop(&config, &gd));
    end_curses();
    return 0;
}