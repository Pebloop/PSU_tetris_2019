/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Parsing of tetriminos' configuration files.
*/

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
        if (current_file == NULL || current_file->d_type != DT_REG)
            continue;
        if (is_wrong_filename(current_file->d_name))
            continue;
        if (get_tetrimino(tetriminos, current_file->d_name) == 84) {
            destroy_tetriminos_list(copy_pointer);
            return (84);
        }
    } while (current_file != NULL);
    closedir(directory);
    return (0);
}

int get_tetrimino(tetrimino_t **tetriminos, char *filename)
{
    int fd = 0;
    char *content = NULL;
    if (open_file(filename, &fd) == 84)
        return (84);
    if (get_file_content(&content, fd) == 84) {
        close(fd);
        return (84);
    }
    close(fd);
    if (is_wrong_format(content) || create_tetrimino(tetriminos) == 84 ||
        parse_file(tetriminos, content, filename) == 84) {
        free(content);
        return (84);
    }
    free(content);
    return (0);
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
        free(list->name);
        destroy_matrix(list->shape, list->height - 1);
        free(list);
        list = copy_pointer;
    }
}