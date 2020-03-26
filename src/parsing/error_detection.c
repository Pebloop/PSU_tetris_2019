/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Detection of eventual errors in tetriminos' configuration files.
*/

#include "fae.h"
#include "tetris.h"

int is_wrong_filename(char *filename)
{
    int filename_len = 0;
    int extension_start = 0;

    filename_len = fae_strlen(filename);
    extension_start = filename_len - 10;
    if (extension_start < 0)
        return (1);
    if (fae_strcmp(".tetrimino", &(filename[extension_start])))
        return (1);
    return (0);
}

int is_wrong_format(char *content)
{
    if (!my_is_int(&content, ' ') || *content != ' ')
        return (1);
    for (; *content == ' '; content++);
    if (!my_is_int(&content, ' ') || *content != ' ')
        return (1);
    for (; *content == ' '; content++);
    if (!my_is_int(&content, '\n') || *content != '\n')
        return (1);
    if (++content == 0)
        return (1);
    for (; *content != 0; content++) {
        if (*content != ' ' && *content != '*' && *content != '\n')
            return (1);
    }
    return (0);
}

int my_is_int(char **str, char end)
{
    if (**str == '-' || **str == '+')
        (*str)++;
    for (; **str != end && **str != 0; (*str)++) {
        if (**str < '0' || '9' < **str)
            return (0);
    }
    return (1);
}

int is_wrong_shape(tetrimino_t *tetriminos, char *content)
{
    int lines = 0;
    int i = 0;

    for (; lines < tetriminos->height && content[i] != 0; i++)
        lines += (content[i] == '\n');
    if (lines != tetriminos->height || content[i] != 0)
        return (1);
    for (int j = 0; j < tetriminos->height; j++) {
        if (is_wrong_line(&content, tetriminos))
            return (1);
    }
    return (0);
}

int is_wrong_line(char **content, tetrimino_t *tetriminos)
{
    int nb_asterisks = 0;
    int cols = 0;
    int trailing_spaces = 0;
    char *ptr = NULL;

    for (; **content != '\n' && **content != 0; (*content)++) {
        cols++;
        nb_asterisks += (**content == '*');
    }
    ptr = *content - 1;
    for (; *ptr != '*'; trailing_spaces++, ptr--);
    if (cols - trailing_spaces > tetriminos->width)
        return (1);
    (*content)++;
    return (0);
}