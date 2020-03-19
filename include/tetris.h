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
#include "game.h"

typedef struct tetrimino {
    char *name;
    int width;
    int height;
    int color;
    int **shape;
    struct tetrimino *next;
} tetrimino_t;

typedef struct keymap {
    int move_left;
    int move_right;
    int rotate;
    int drop;
    int quit;
    int pause;
} keymap_t;

typedef struct config {
    tetrimino_t *tetri_list;
    int tlist_size;
    int level;
    int map_width;
    int map_height;
    int hide_next;
    int debug_mode;
    keymap_t key;
} config_t;

// display_usage.c
int display_usage(void);

/*    PARSING    */

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
int init_tetrimino(tetrimino_t **tetriminos, char *content, char *filename);
int get_tetrimino_name(tetrimino_t *tetrimino, char *filename);
int parse_file(tetrimino_t *tetrimino, char *content);
int get_next_nbr(char **str, char end);

// get_shape.c
int get_shape(tetrimino_t *tetriminos, char *content);
int create_matrix(tetrimino_t *tetriminos);
void destroy_matrix(int **matrix, int last_line);

// error_detection.c
int is_wrong_filename(char *filename);
int is_wrong_format(char *content);
int my_is_int(char **str, char end);
int is_wrong_shape(tetrimino_t *tetriminos, char *content);
int is_wrong_line(char **content, tetrimino_t *tetriminos);

/*    CONFIGURATION    */

// init_config.c
int init_config(config_t *config, int argc, char **argv);
void init_keys_default(config_t *config);
int init_keys_args(config_t *config, int argc, char **argv);
int set_option(config_t *config, int option);

// config_controls.c
int config_left(config_t *config);
int config_right(config_t *config);
int config_rotate(config_t *config);
int config_drop(config_t *config);

// config_ui.c
int config_quit(config_t *config);
int config_pause(config_t *config);

// config_options.c
int config_level(config_t *config);
int config_next(config_t *config);
int config_debug(config_t *config);

/*    DEBUG MODE    */

// debug_mode.c
void launch_debug_mode(config_t config);
void sort_tetriminos_list(tetrimino_t *list, int size);
void display_tetriminos_list(tetrimino_t *list, int size);
void display_tetrimino_shape(tetrimino_t *tetrimino);

/*    GAME    */

// launch_game.c
int launch_game(config_t config);

// game_loop.c
int game_loop(config_t *config, game_data_t *gd);

// set_move.c
void set_move(game_data_t *gd, config_t config);

// display_game.c
void diplay_game(config_t config, game_data_t *gd);

// move_tetrimino.c

#endif // DEF_TETRIS