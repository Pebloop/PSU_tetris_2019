/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Main function
*/

#include <stddef.h>
#include "tetris.h"
#include "fae.h"

int main(int argc, char **argv)
{
    config_t config = {0};

    if (argc == 2 && !fae_strcmp(argv[1], "--help"))
        return display_usage();
    if (init_config(&config, argc, argv))
        return 84;
    if (config.debug_mode)
        launch_debug_mode(config);
    launch_game(config);
    destroy_tetriminos_list(config.tetri_list);
    return (0);
}