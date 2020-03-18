/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Opening and reading of the tetriminos' configuration files.
*/

#include "fae.h"
#include "tetris.h"

int open_file(char *filename, int *fd)
{
    char *filepath = NULL;

    if (my_strcat(&filepath, "tetriminos/", filename) == 84)
        return (84);
    *fd = open(filepath, O_RDONLY);
    free(filepath);
    if (*fd == -1)
        return (84);
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

int get_file_content(char **content, int fd)
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