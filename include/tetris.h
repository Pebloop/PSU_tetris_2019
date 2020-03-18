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

typedef struct config {
    tetrimino_t *tetri_list;
    int level;
    int map_width;
    int map_height;
    int hide_next;
    int debug_mode;
    int key_move_left;
    int key_move_right;
    int key_rotate;
    int key_drop;
    int key_quit;
    int key_pause;
} config_t;

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

// init_config.c
void init_config(config_t *config);

// tetris.h
int display_usage(void);

//launch_game.c
int launch_game(config_t config);

#endif // DEF_TETRIS