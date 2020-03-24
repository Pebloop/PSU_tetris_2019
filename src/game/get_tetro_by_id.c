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

tetrimino_t *get_tetro_by_id(config_t config, int index)
{
    tetrimino_t *current = config.tetri_list;

    for (int i = 0; current->next && i < index; i++)
        current = current->next;
    return current;
}