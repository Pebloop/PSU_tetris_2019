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
#include "vector.h"

static vector_t calcul_rotation_time(int x, int y, int size)
{
    vector_t result = {x, y};

    result.x = size - y - 1;
    result.y = x; 
    return result;
}

vector_t calcul_rotation(tetrimino_t *current, game_data_t *gd,
    int x, int y)
{
    vector_t pixel = {x, y};
    int width = current->width;
    int height = current->height;
    int square = (width > height) ? width : height;

    if (width < height) {
        pixel.x += ((height - width) / 2) + 1;
    }
    if (width > height)
        pixel.y += ((width - height) / 2) + 1;
    for (int i = 0; i < gd->current_move.rotation; i++) {
        pixel = calcul_rotation_time(pixel.x, pixel.y,
            square);
    }
    return pixel;
}

