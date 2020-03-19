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
    /*while (config.tetri_list != NULL) {
        printf("width : %i\n", config.tetri_list->width);
        printf("height : %i\n", config.tetri_list->height);
        printf("color : %i\n", config.tetri_list->color);
        for (int i = 0; i < config.tetri_list->height; i++) {
            for (int j = 0; j < config.tetri_list->width; j++) {
                printf("%i", config.tetri_list->shape[i][j]);
            }
            printf("\n");
        }
        config.tetri_list = config.tetri_list->next;
        printf("\n\n");
    }*/

    launch_game(config);
    destroy_tetriminos_list(config.tetri_list);

    /*printf("level : %i\n", config.level);
    printf("hide_next : %i\n", config.hide_next);
    printf("debug_mode : %i\n", config.debug_mode);
    printf("map_width : %i\n", config.map_width);
    printf("map_height : %i\n", config.map_height);
    printf("move_left : %i\n", config.key.move_left);
    printf("move_right : %i\n", config.key.move_right);
    printf("rotate : %i\n", config.key.rotate);
    printf("drop : %i\n", config.key.drop);
    printf("pause : %i\n", config.key.pause);
    printf("quit : %i\n", config.key.quit);*/

    return (0);
}