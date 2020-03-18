/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Header
*/

#ifndef DEF_TETRIS
#define DEF_TETRIS

typedef struct tetrimino {
    char *name;
    int width;
    int height;
    int color;
    int **shape;
    struct tetrimino *next;
} tetrimino_t;

// parsing.c
int get_tetriminos_list(tetrimino_t **tetriminos);
int get_tetrimino(tetrimino_t **tetriminos, char *file_name);
int my_strcat(char **dest, char *str1, char *str2);
int get_content_of_file(char **content, int fd);
int parse_file(tetrimino_t **tetriminos, char *content);
int get_shape(tetrimino_t *tetriminos, char *content);
void destroy_matrix(int **matrix, int last_line);
int create_tetrimino(tetrimino_t **tetriminos);
void destroy_tetriminos_list(tetrimino_t *list);
int get_next_nbr(char **str, char end);

#endif // DEF_TETRIS