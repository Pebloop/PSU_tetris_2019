/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Header
*/

#ifndef DEF_TETRIS
#define DEF_TETRIS

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct tetrimino {
    char *name;
    int width;
    int height;
    int color;
    int **shape;
    struct tetrimino *next;
} tetrimino_t;

// get_tetriminos_list.c
int get_tetriminos_list(tetrimino_t **tetriminos);
int get_tetrimino(tetrimino_t **tetriminos, char *filename);
int create_tetrimino(tetrimino_t **tetriminos);
void destroy_tetriminos_list(tetrimino_t *list);

// get_file_content.c
int open_file(char *filename, int *fd);
int my_strcat(char **dest, char *str1, char *str2);
int get_file_content(char **content, int fd);

// initialize_tetrimino.c
int parse_file(tetrimino_t **tetriminos, char *content, char *filename);
int get_tetrimino_name(tetrimino_t *tetrimino, char *filename);
int get_next_nbr(char **str, char end);

// get_shape.c
int get_shape(tetrimino_t *tetriminos, char *content);
int create_matrix(tetrimino_t *tetriminos);
void destroy_matrix(int **matrix, int last_line);

// error_detection.c
int is_wrong_filename(char *filename);
int is_wrong_format(char *content);
int my_is_int(char **str, char end);
int check_shape(tetrimino_t *tetriminos, char *content);

#endif // DEF_TETRIS