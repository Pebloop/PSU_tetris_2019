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

void easy_spin_update(game_data_t *gd)
{
    gd->easy_spin++;
    if (gd->easy_spin < 15)
        clock_init(&(gd->turn));
}

int abs(int i)
{
    if (i < 0)
        return -i;
    return i;
}