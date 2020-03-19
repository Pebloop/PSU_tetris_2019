/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Displays help.
*/

#include "fae.h"

int display_usage(void)
{
    fae_putstr("Usage:    ./tetris [options]\n");
    fae_putstr("Options:\n --help               Display this help\n");
    fae_putstr(" -L --level={num}     Start Tetris at level num (def: 1)\n");
    fae_putstr(" -l --key-left={K}    ");
    fae_putstr("Move the tetrimino LEFT using the K key (def: left arrow)\n");
    fae_putstr(" -r --key-right={K}   Move the tetrimino RIGHT using ");
    fae_putstr("the K key (def: right arrow)\n");
    fae_putstr(" -t --key-turn={K}    TURN the tetrimino clockwise ");
    fae_putstr("90d using the K key (def: top arrow)\n");
    fae_putstr(" -d --key-drop={K}    DROP the tetrimino using");
    fae_putstr(" the K key (def: down arrow)\n");
    fae_putstr(" -q --key-quit={K}    QUIT the game ");
    fae_putstr("using the K key (def: 'q' key)\n");
    fae_putstr(" -p --key-pause={K}   PAUSE/RESTART the game using ");
    fae_putstr("the K key (def: space bar)\n");
    fae_putstr(" --map-size={row,col} Set the numbers of rows and ");
    fae_putstr("columns of the map (def: 20, 10)\n");
    fae_putstr(" -w --without-next    Hide next tetrimino (def: false)\n");
    fae_putstr(" -D --debug           Debug mode (def: false)\n");
    return 0;
}