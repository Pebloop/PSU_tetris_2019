/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Initializing of tetriminos : name, height, width, color and shape.
*/

#include "fae.h"
#include "tetris.h"

int parse_file(tetrimino_t **tetriminos, char *content, char *filename)
{
    tetrimino_t *last = NULL;

    for (last = *tetriminos; last->next != NULL; last = last->next);
    if (get_tetrimino_name(last, filename) == 84)
        return (84);
    last->width = get_next_nbr(&content, ' ');
    content++;
    last->height = get_next_nbr(&content, ' ');
    content++;
    last->color = get_next_nbr(&content, '\n');
    content++;
    if (last->color < 0 || 15 < last->color) {
        free(last->name);
        return (84);
    }
    if (get_shape(last, content) == 84) {
        free(last->name);
        return (84);
    }
    return (0);
}

int get_tetrimino_name(tetrimino_t *tetrimino, char *filename)
{
    int filename_len = 0;

    filename_len = fae_strlen(filename);
    tetrimino->name = malloc(sizeof(char) + (filename_len - 9));
    if (tetrimino->name == NULL)
        return (84);
    for (int i = 0; i < filename_len - 10; i++)
        tetrimino->name[i] = filename[i];
    tetrimino->name[filename_len - 10] = 0;
    return (0);
}

int get_next_nbr(char **str, char end)
{
    int nbr = 0;
    char first_char = 0;

    first_char = **str;
    for (; **str == '-' || **str == '+' || **str == '0'; (*str)++);
    for (; **str != end && **str != 0; (*str)++)
        nbr = nbr * 10 + (**str - 48);
    if (first_char == '-')
        nbr = nbr * (-1);
    return (nbr);
}