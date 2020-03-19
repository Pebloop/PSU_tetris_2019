/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Displays the game's configuration until the user presses a key.
*/

#include "fae.h"
#include "tetris.h"

void launch_debug_mode(config_t config)
{
    fae_put("*** DEBUG MODE ***\n");
    fae_put("Key Left : %c\n", config.key.move_left);
    fae_put("Key Right : %c\n", config.key.move_right);
    fae_put("Key Turn : %c\n", config.key.rotate);
    fae_put("Key Drop : %c\n", config.key.drop);
    fae_put("Key Quit : %c\n", config.key.quit);
    fae_put("Key Pause : %c\n", config.key.pause);
    fae_put("Next : %s\n", config.hide_next ? "No" : "Yes");
    fae_put("Level : %d\n", config.level);
    fae_put("Size : %d*%d\n", config.map_height, config.map_width);
    fae_put("Tetriminos : %d\n", config.tlist_size);
    display_tetriminos_list(config.tetri_list, config.tlist_size);
    fae_put("Press any key to start Tetris");
    // while (/* no key pressed*/); // TODO
}

void sort_tetriminos_list(tetrimino_t *list, int size)
{
    // TODO
}

void display_tetriminos_list(tetrimino_t *list, int size)
{
    sort_tetriminos_list(list, size);
    while (list != NULL) {
        fae_put("Tetriminos : ");
        fae_put("Name %s : ", list->name);
        if (list->shape != NULL) {
            fae_put("Size %d*%d : ", list->width, list->height);
            fae_put("Color %d :\n", list->color);
            display_tetrimino_shape(list);
        } else
            fae_put("Error\n");
        list = list->next;
    }
}

void display_tetrimino_shape(tetrimino_t *tetrimino)
{
    for (int i = 0; i < tetrimino->height; i++) {
        for (int j = 0; j < tetrimino->width; j++) {
            fae_put("%c", tetrimino->shape[i][j] ? '*' : ' ');
        }
        fae_put("\n");
    }
}