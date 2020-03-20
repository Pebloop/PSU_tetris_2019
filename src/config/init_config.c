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

    opterr = 0;
    while ((option = getopt(argc, argv, "L:l:r:t:d:q:p:wD")) != -1) {
        if (option == '?' || set_option(config, option) == 84)
            return (84);
    }
    return (0);
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