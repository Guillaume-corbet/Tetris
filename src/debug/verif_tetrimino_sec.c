/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** verif_tetrimino_sec
*/

#include "../../tetris.h"

int verif_tetrimino_five(char verif)
{
    if (verif != '\n' && verif != '\0' && verif != ' ' && verif != '*')
        return (1);
    return (0);
}

void verif_tetrimino_four(tetris_t *tet, struct node *tmp)
{
    int x = 0;
    int y = 0;
    int error = 0;

    while (tmp->tetri->tetrimino[y] != NULL) {
        while (tmp->tetri->tetrimino[y][x] != '\0') {
            error = error + verif_tetrimino_five(tmp->tetri->tetrimino[y][x]);
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
    if (error > 0)
        tmp->tetri->error = 1;
}