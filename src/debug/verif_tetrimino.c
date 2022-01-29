/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** verif_tetrimino
*/

#include "../../tetris.h"

void verif_tetrimino_third(tetris_t *tet, struct node *tmp)
{
    int y = 0;
    int x = my_strlen(tmp->tetri->tetrimino[y]);
    int max = 0;

    while (tmp->tetri->tetrimino[y] != NULL) {
        while (tmp->tetri->tetrimino[y][x] == ' ')
            x = x - 1;
        if (x > max)
            max = x;
        y = y + 1;
        if (tmp->tetri->tetrimino[y] != NULL)
            x = my_strlen(tmp->tetri->tetrimino[y]) - 1;
    }
    if (max != tmp->tetri->width)
        tmp->tetri->error = 1;
    if (y != tmp->tetri->height)
        tmp->tetri->error = 1;
    y = 0;
    max = 0;
}

void verif_tetrimino_sec(tetris_t *tet)
{
    struct node *tmp = tet->p_list->p_head;

    while (tmp) {
        if (tmp->tetri->error != 1)
            verif_tetrimino_third(tet, tmp);
        if (tmp->tetri->error != 1)
            verif_tetrimino_four(tet, tmp);
        tmp = tmp->p_next;
    }
}

void verif_tetrimino(tetris_t *tet)
{
    struct node *tmp = tet->p_list->p_head;

    while (tmp) {
        if (tmp->tetri->height == 0 || tmp->tetri->width == 0
        || tmp->tetri->color < 0 || tmp->tetri->color > 15)
            tmp->tetri->error = 1;
        tmp = tmp->p_next;
    }
    verif_tetrimino_sec(tet);
}