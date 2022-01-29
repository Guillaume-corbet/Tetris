/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** left
*/

#include "../../tetris.h"

int verif_go_left(tetris_t *tet)
{
    int x = 1;
    int y = 0;

    while (y < tet->fl->height) {
        if (tet->g_tet->tetr[y][0] == '*')
            return (1);
        y = y + 1;
    }
    y = 0;
    while (y < tet->fl->height) {
        while (x < tet->fl->width) {
            if (tet->g_tet->tetr[y][x] == '*'
            && (tet->g_tet->map[y][x - 1] == '*'
            || x == 0))
                return (1);
            x = x + 1;
        }
        x = 1;
        y = y + 1;
    }
    return (0);
}

void go_left(tetris_t *tet)
{
    int x = 1;
    int y = 0;

    if (verif_go_left(tet) == 1)
        return;
    while (x < tet->fl->width) {
        while (y < tet->fl->height) {
            if (tet->g_tet->tetr[y][x] == '*'
            && tet->g_tet->tetr[y][x - 1] == ' ') {
                tet->g_tet->tetr[y][x] = ' ';
                tet->g_tet->tetr[y][x - 1] = '*';
            }
            y = y + 1;
        }
        y = 0;
        x = x + 1;
    }
}