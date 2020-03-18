/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Parsing of tetriminos' configuration files.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fae.h"
#include "tetris.h"

int get_tetriminos_list(tetrimino_t **tetriminos)
{
    DIR *directory = NULL;
    struct dirent *current_file = NULL;
    tetrimino_t *copy_pointer = *tetriminos;

    directory = opendir("tetriminos");
    if (directory == NULL)
        return (84);
    do {
        current_file = readdir(directory);
        if (current_file == NULL || current_file->d_type != DT_REG /* || !is_tetrimino_file(name)*/)
            continue;
        if (get_tetrimino(tetriminos, current_file->d_name) == 84) {
            destroy_tetriminos_list(copy_pointer);
            return (84);
        }
    } while (current_file != NULL);
    closedir(directory);
    return (0);
}

int get_tetrimino(tetrimino_t **tetriminos, char *file_name)
{
    int fd = 0;
    char *content = NULL;
    char *filepath = NULL;

    if (my_strcat(&filepath, "tetriminos/", file_name) == 84)
        return (84);
    fd = open(filepath, O_RDONLY);
    free(filepath);
    if (fd == -1)
        return (84);
    if (get_content_of_file(&content, fd) == 84) {
        close(fd);
        return (84);
    } else if (parse_file(tetriminos, content) == 84) {
        free(content);
        close(fd);
        return (84);
    }
    free(content);
    close(fd);
    return (0);
}

int my_strcat(char **dest, char *str1, char *str2)
{
    int length1 = 0;
    int length2 = 0;

    length1 = fae_strlen(str1);
    length2 = fae_strlen(str2);
    *dest = malloc(sizeof(char) * (length1 + length2 + 1));
    if (*dest == NULL)
        return (84);
    for (int i = 0; i < length1; i++)
        (*dest)[i] = str1[i];
    for (int i = 0; i < length2; i++)
        (*dest)[i + length1] = str2[i];
    (*dest)[length1 + length2] = 0;
    return (0);
}

int get_content_of_file(char **content, int fd)
{
    struct stat buffer;
    int size_of_read = 0;

    if (fstat(fd, &buffer) == -1)
        return (1);
    *content = malloc(sizeof(char) * buffer.st_size + 1);
    if (*content == NULL)
        return (84);
    size_of_read = read(fd, *content, buffer.st_size);
    if (size_of_read != buffer.st_size)
        return (84);
    (*content)[buffer.st_size] = 0;
    return (0);
}

int parse_file(tetrimino_t **tetriminos, char *content)
{
    tetrimino_t *last = NULL;

    if (create_tetrimino(tetriminos) == 84)
        return (84);
    last = *tetriminos;
    for (; last->next != NULL; last = last->next);
    //last->name = ; TODO
    last->width = get_next_nbr(&content, ' ');
    content++;
    last->height = get_next_nbr(&content, ' ');
    content++;
    last->color = get_next_nbr(&content, '\n');
    content++;
    if (get_shape(last, content) == 84)
        return (84);
    return (0);
}

int get_shape(tetrimino_t *tetriminos, char *content)
{
    tetriminos->shape = malloc(sizeof(int *) * (tetriminos->height));
    if (tetriminos->shape == NULL)
        return (84);
    for (int i = 0; i < tetriminos->height; i++) {
        tetriminos->shape[i] = malloc(sizeof(int) * tetriminos->width);
        if (tetriminos->shape[i] == NULL)
            destroy_matrix(tetriminos->shape, i - 1);
        for (int j = 0; j < tetriminos->width; j++)
            tetriminos->shape[i][j] = 0;
    }
    for (int i = 0; i < tetriminos->height; i++) {
        for (int j = 0; j < tetriminos->width && *content != '\n'; j++) {
            tetriminos->shape[i][j] = (*content == '*');
            content++;
        }
        for (; *content == ' ' || *content == '\n'; content++);
    }
    return (0);
}

void destroy_matrix(int **matrix, int last_line)
{
    for (int i = 0; i <= last_line; i++)
        free(matrix[i]);
    free(matrix);
}

int create_tetrimino(tetrimino_t **tetriminos)
{
    tetrimino_t *new_tetrimino = NULL;
    tetrimino_t *copy_pointer = *tetriminos;

    new_tetrimino = malloc(sizeof(tetrimino_t));
    if (new_tetrimino == NULL)
        return (84);
    new_tetrimino->name = NULL;
    new_tetrimino->width = 0;
    new_tetrimino->height = 0;
    new_tetrimino->color = 0;
    new_tetrimino->shape = NULL;
    new_tetrimino->next = NULL;
    if (*tetriminos == NULL)
        *tetriminos = new_tetrimino;
    else {
        for (; copy_pointer->next != NULL; copy_pointer = copy_pointer->next);
        copy_pointer->next = new_tetrimino;
    }
    return (0);
}

void destroy_tetriminos_list(tetrimino_t *list)
{
    tetrimino_t *copy_pointer = NULL;

    while (list != NULL) {
        copy_pointer = list->next;
        free(list);
        list = copy_pointer;
    }
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