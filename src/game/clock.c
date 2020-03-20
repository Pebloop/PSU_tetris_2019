/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** clock
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "fae.h"
#include "tetris.h"
#include "ncurses.h"
#include "game.h"

void clock_init(clockss_t *timer)
{
    timer->start = clock();
    timer->current = 0;
}

void clock_update(clockss_t *timer)
{
    timer->current = (double)(clock() - timer->start) / CLOCKS_PER_SEC;
}

int clock_get_second(clockss_t timer)
{
    return (int)timer.current;
}

int clock_get_minute(clockss_t timer)
{
    return (int)(timer.current / 60);
}