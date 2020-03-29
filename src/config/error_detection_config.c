/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Error detection during config of keys, tetriminos, options, etc.
*/

#include "fae.h"
#include "tetris.h"

void check_tetriminos_sizes(config_t *config)
{
    for (tetrimino_t *t = config->tetri_list; t != NULL; t = t->next) {
        if (t->width > config->map_width || t->height > config->map_height) {
            t->width = -1;
            t->height = -1;
            t->color = -1;
            t->shape = NULL;
        }
    }
}

int is_abbreviation_longopt(int option, char **argv)
{
    static int prev_optind = 1;
    int is_abbr = 0;
    char *short_opt = "LlrtdqpwDs";
    char *long_opt[10] = {"level", "key-left", "key-right", "key-turn",
        "key-drop", "key-quit", "key-pause", "without-next", "debug",
        "map-size"};

    for (int i = 0; i < 10 && !is_abbr; i++) {
        if (option == short_opt[i] && argv[prev_optind][1] == '-')
            is_abbr = !is_whole_long_opt(long_opt[i], &(argv[prev_optind][2]));
    }
    prev_optind = optind;
    return (is_abbr);
}

int is_whole_long_opt(char *opt, char *argv)
{
    if (!fae_strcmp(opt, argv))
        return (1);
    if (fae_strlen(opt) + 2 > fae_strlen(argv))
        return (0);
    if (argv[fae_strlen(opt)] != '=')
        return (0);
    return (1);
}