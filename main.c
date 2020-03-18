/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Main function
*/

#include <stddef.h>
#include "tetris.h"

int main(int argc, char **argv)
{
    config_t config = {0};

    init_config(&config);
    if (get_tetriminos_list(&(config.tetri_list)) == 84)
        return (84);

    while (config.tetri_list != NULL) {
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
    }
    launch_game(config);
    destroy_tetriminos_list(config.tetri_list);
    return (0);
}