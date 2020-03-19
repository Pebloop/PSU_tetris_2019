/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Header
*/

#ifndef GAME_H
#define GAME_H

typedef struct move {
    int tetrimino;
    int pos_x;
    int pos_y;
    int rotation;
} move_t;

typedef struct game_data {
    int **board;
    move_t current_move;
    int next;
    int lines;
    int score;
    int timer;
    int turn;
} game_data_t;

#endif // GAME_H