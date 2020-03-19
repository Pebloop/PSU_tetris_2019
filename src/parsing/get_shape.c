/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Initializing of tetriminos' shapes
*/

#include "tetris.h"

int get_shape(tetrimino_t *tetriminos, char *content)
{
    if (is_wrong_shape(tetriminos, content))
        return (-1);
    if (create_matrix(tetriminos) == 84)
        return (84);
    for (int i = 0; i < tetriminos->height; i++) {
        for (int j = 0; j < tetriminos->width && *content != '\n'; j++) {
            tetriminos->shape[i][j] = (*content == '*');
            content++;
        }
        for (; *content == ' ' || *content == '\n'; content++);
    }
    return (0);
}

int create_matrix(tetrimino_t *tetriminos)
{
    tetriminos->shape = malloc(sizeof(int *) * (tetriminos->height));
    if (tetriminos->shape == NULL)
        return (84);
    for (int i = 0; i < tetriminos->height; i++) {
        tetriminos->shape[i] = malloc(sizeof(int) * tetriminos->width);
        if (tetriminos->shape[i] == NULL) {
            destroy_matrix(tetriminos->shape, i - 1);
            return (84);
        }
        for (int j = 0; j < tetriminos->width; j++)
            tetriminos->shape[i][j] = 0;
    }
    return (0);
}

void destroy_matrix(int **matrix, int last_line)
{
    for (int i = 0; i <= last_line; i++)
        free(matrix[i]);
    free(matrix);
}