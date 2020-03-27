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

void draw_cadran(int x, int y, int width, int height)
{
    for (int xo = 0; xo < width; xo++)
        mvprintw(y, x + xo, "%c",
                (xo == 0 || xo + 1 == width) ? '*' : '-');
    for (int xo = 0; xo < width; xo++)
        mvprintw(y + height, x + xo, "%c",
                (xo == 0 || xo + 1 == width) ? '*' : '-');
    for (int i = 1; i < height; i++) {
        for (int xo = 0; xo < width; xo++)
            mvprintw(y + i, x + xo, "%c",
                (xo == 0 || xo + 1 == width) ? '|' : ' ');
    }
}

void draw_next(config_t config, game_data_t *gd, int xo, int yo)
{
    tetrimino_t *current = get_tetro_by_id(config, gd->next);

    for (int y = 0; y < current->height; y++) {
        for (int x = 0; x < current->width; x++) {
            if (current->shape[y][x]) {
                attron(COLOR_PAIR(current->color));
                mvprintw(yo + y, xo + x, " ");
                attroff(COLOR_PAIR(current->color));
            }
        }
    }
}

void display_next(config_t config, game_data_t *gd)
{
    tetrimino_t *current = get_tetro_by_id(config, gd->next);
    int max_x = 4;
    int max_y = 0;
    int center_x = config.map_width + 4;
    int center_y = 2;

    for (tetrimino_t *t = config.tetri_list; t; t = t->next) {
        max_x = (max_x < t->width) ? t->width : max_x;
        max_y = (max_y < t->height) ? t->height : max_y;
    }
    center_x += (max_x - current->width) / 2;
    center_y += (max_y - current->height) / 2;
    draw_cadran(config.map_width + 3, 0, max_x + 2, max_y + 2);
    mvprintw(1, config.map_width + 4, "next");
    draw_next(config, gd, center_x, center_y);
}

void display_score(config_t config, game_data_t *gd)
{
    int max_x = 5;
    int max_y = 0;
    int ox = config.map_width + 3;
    int oy = max_y + 3;

    for (tetrimino_t *t = config.tetri_list; t; t = t->next) {
        max_x = (max_x < t->width) ? t->width : max_x;
        max_y = (max_y < t->height) ? t->height : max_y;
    }
    oy += max_y;
    draw_cadran(ox, oy, 24, 8);
    mvprintw(oy + 1, ox + 1, "score : %d", gd->score);
    mvprintw(oy + 2, ox + 1, "high score : %d", gd->highscore);
    mvprintw(oy + 4, ox + 1, "timer : %d:%02d", clock_get_minute(gd->timer), clock_get_second(gd->timer) % 60);
    mvprintw(oy + 6, ox + 1, "line : %d", gd->lines);
    mvprintw(oy + 7, ox + 1, "level : %d", config.level);
}