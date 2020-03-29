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

void gml_if(vector_t pixel, vector_t *data, vector_t *width)
{
    if (pixel.x < data->x) {
        data->x = pixel.x;
        width->x = pixel.x;
    } else if (pixel.x > width->y)
        width->y = pixel.x;
    data->y = width->y - width->x + 1;
}

vector_t get_most_left(tetrimino_t *current, game_data_t *gd)
{
    vector_t pixel = calcul_rotation(current, gd, 0, 0);
    vector_t data = {pixel.x, 1};
    vector_t width = {pixel.x, pixel.x};

    for (int y = 0; y < current->height; y++) {
        for (int x = 0; x < current->width; x++) {
            pixel = calcul_rotation(current, gd, x, y);
            gml_if(pixel, &data, &width);
        }       
    }
    return data;
}

void gt_if(vector_t pixel, int *data)
{
    if (pixel.y < data) {
        data = pixel.y;
    }
}

int get_top(tetrimino_t *current, game_data_t *gd)
{
    vector_t pixel = calcul_rotation(current, gd, 0, 0);
    int data = pixel.y;

    for (int y = 0; y < current->height; y++) {
        for (int x = 0; x < current->width; x++) {
            pixel = calcul_rotation(current, gd, x, y);
            gt_if(pixel, &data);
        }
    }
    return data;
}

void set_move(game_data_t *gd, config_t config)
{
    tetrimino_t *current = 0;
    vector_t center = {0};

    gd->current_move.pos_x = config.map_width / 2;
    gd->current_move.pos_y = 0;
    gd->current_move.rotation = 0;
    gd->current_move.tetrimino = gd->next;
    current = get_tetro_by_id(config, gd->current_move.tetrimino);
    center = get_most_left(current, gd);
    gd->current_move.pos_x -= center.x;
    gd->current_move.pos_x -= center.y / 2;
    gd->current_move.pos_x -= (center.y % 2) ? 1 : 0;
    gd->current_move.pos_y -= get_top(current, gd);
    gd->next = rand() % (config.tlist_size);
}