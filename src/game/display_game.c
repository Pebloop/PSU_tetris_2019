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

void display_border_line(config_t config, int i)
{
    for (int x = 1; x <= config.map_width; x++)
        mvprintw(i, x, "-");
    mvprintw(i, 0, "*");
    mvprintw(i, config.map_width + 1, "*");
}

void display_bloc(config_t config, game_data_t *gd, int i, int x)
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

tetrimino_t *get_tetro_by_id(config_t config, int index)
{
    tetrimino_t *current = config.tetri_list;

    for (int i = 0; current->next && i < index; i++)
        current = current->next;
    return current;
}

void display_player(config_t config, game_data_t *gd)
{
    tetrimino_t *current = get_tetro_by_id(config, gd->current_move.tetrimino);

    for (int y = 0; y < current->height; y++) {
        for (int x = 0; x < current->width; x++) {
            if (current->shape[y][x]) {
                attron(COLOR_PAIR(current->color));
                mvprintw(gd->current_move.pos_y + 1 + y, gd->current_move.pos_x + 1 + x, " ");
                attroff(COLOR_PAIR(current->color));
            }
        }
    }
}

void diplay_game(config_t config, game_data_t *gd)
{
    for (int i = 0; i <= config.map_height + 1; i++) {
        display_line(config, gd, i);
    }
    display_player(config, gd);
}