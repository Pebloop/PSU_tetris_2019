/*
** EPITECH PROJECT, 2020
** navy
** File description:
** Main function
*/

#include <stddef.h>
#include "tetris.h"

int main(int argc, char **argv)
{
    tetrimino_t *tetriminos = NULL;

    if (get_tetriminos_list(&tetriminos) == 84)
        return (84);

    while (tetriminos != NULL) {
        printf("width : %i\n", tetriminos->width);
        printf("height : %i\n", tetriminos->height);
        printf("color : %i\n", tetriminos->color);
        for (int i = 0; i < tetriminos->height; i++) {
            for (int j = 0; j < tetriminos->width; j++) {
                printf("%i", tetriminos->shape[i][j]);
            }
            printf("\n");
        }
        tetriminos = tetriminos->next;
        printf("\n\n");
    }

    destroy_tetriminos_list(tetriminos);
    return (0);
}