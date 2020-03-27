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

int get_high_score(void)
{
    int fd = open("score", O_RDONLY);
    int size = 0;
    char bf[6];
    int result = 0;

    if (fd == -1)
        return 0;
    size = read(fd, &bf, 6);
    for (int i = 0; i < size; i++) {
        if (bf[i] < 1 || bf[i] > 10)
            return 0;
        result *= 10;
        result += bf[i] - 1;
    }
    return result;
}

void set_high_score(int score)
{
    int fd = (score) ?
        open("score", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR) : -1;
    char bf[6] = {-1};
    char reverse[6] = {-1};
    int size = 0;

    if (fd == -1)
        return;
    for (int i = 0; i < 6 && score; i++) {
        bf[i] = (score % 10) + 1;
        score /= 10;
        size++;
    }
    for (int i = 0; i < size; i++)
        reverse[i] = bf[size - i - 1];
    write(fd, reverse, size);
}