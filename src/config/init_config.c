/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Initializes the game's configuration (tetriminos, level, keys, options).
*/

#include <unistd.h>
#include "tetris.h"
#include "ncurses.h"

int init_config(config_t *config, int argc, char **argv)
{
    config->tetri_list = NULL;
    int correct_tetriminos = 0;

    if (get_tetriminos_list(&(config->tetri_list)) == 84)
        return (84);
    init_keys_default(config);
    for (tetrimino_t *t = config->tetri_list; t != NULL; t = t->next) {
        if (t->shape != NULL)
            correct_tetriminos++;
    }
    if (!correct_tetriminos)
        return (84);
    if (init_keys_args(config, argc, argv) == 84)
        return (84);
    return (0);
}

void init_keys_default(config_t *config)
{
    config->tlist_size = 0;
    for (tetrimino_t *t = config->tetri_list; t; t = t->next)
        config->tlist_size += 1;
    config->level = 1;
    config->hide_next = 0;
    config->debug_mode = 0;
    config->map_width = 10;
    config->map_height = 20;
    config->key.move_left = KEY_LEFT;
    config->key.move_right = KEY_RIGHT;
    config->key.rotate = KEY_UP;
    config->key.drop = KEY_DOWN;
    config->key.pause = ' ';
    config->key.quit = 'q';
}

int init_keys_args(config_t *config, int argc, char **argv)
{
    int option = 0;
    struct option long_options[11];
    char *names[9] = {"level", "key-left", "key-right", "key-turn", "key-drop",
        "key-quit", "key-payse", "without-next", "debug"};

    opterr = 0;
    init_long_options(long_options, names);
    while ((option = getopt(argc, argv, "L:l:r:t:d:q:p:wD")) != -1) {
        if (option == '?' || set_option(config, option) == 84)
            return (84);
    }
    return (0);
}

void init_long_options(struct option long_options[11], char *names[9])
{
    char *values = "LlrtdqpwD";
    int has_args[9] = {1, 1, 1, 1, 1, 1, 1, 0, 0};

    for (int i = 0; i < 9; i++) {
        long_options[i].name = names[i];
        long_options[i].has_arg = has_args[i];
        long_options[i].flag = NULL;
        long_options[i].val = values[i];
    }
    long_options[9].name = "map-size";
    long_options[9].has_arg = 1;
    long_options[9].flag = NULL;
    long_options[9].val = (int)'s';
    long_options[10].name = 0;
    long_options[10].has_arg = 0;
    long_options[10].flag = 0;
    long_options[10].val = 0;
}

int set_option(config_t *config, int option)
{
    char *options = "LlrtdqpwD";
    int (*functions[9])(config_t *) = {config_level, config_left,
        config_right, config_rotate, config_drop, config_quit, config_pause,
        config_next, config_debug};

    for (int i = 0; i < 9; i++) {
        if (option == options[i])
            return (functions[i](config));
    }
    return (84);
}