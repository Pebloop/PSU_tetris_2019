/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Initializing of tetriminos : name, height, width, color and shape.
*/

#include "fae.h"
#include "tetris.h"

int init_tetrimino(tetrimino_t **tetriminos, char *content, char *filename)
{
    tetrimino_t *last = NULL;
    int return_value = 0;

    for (last = *tetriminos; last->next != NULL; last = last->next);
    if (get_tetrimino_name(last, filename) == 84)
        return (84);
    if (is_wrong_format(content))
        return (-1);
    return_value = parse_file(last, content);
    if (return_value == 84) {
        free(last->name);
        return (84);
    } else if (return_value == -1) {
        last->width = -1;
        last->height = -1;
        last->color = -1;
        last->shape = NULL;
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

int parse_file(tetrimino_t *tetrimino, char *content)
{
    tetrimino->width = get_next_nbr(&content, ' ');
    content++;
    tetrimino->height = get_next_nbr(&content, ' ');
    content++;
    tetrimino->color = get_next_nbr(&content, '\n');
    content++;
    if (tetrimino->color < 0 || 15 < tetrimino->color)
        return (-1);
    return (get_shape(tetrimino, content));
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