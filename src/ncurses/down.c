/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** down
*/

#include "../../tetris.h"

void transfert_tetri(tetris_t *tet)
{
    int x = 0;
    int y = 0;

    while (y < tet->fl->height) {
        while (x <tet->fl->width) {
            if (tet->g_tet->tetr[y][x] == '*') {
                tet->g_tet->map[y][x] = tet->g_tet->tetr[y][x];
                tet->g_tet->tetr[y][x] = ' ';
            }
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
}

int verif_go_down(tetris_t *tet)
{
    int x = 0;
    int y = tet->fl->height - 1;

    while (y >= 0) {
        while (x < tet->fl->width) {
            if (tet->g_tet->tetr[y][x] == '*' && (y == tet->fl->height - 1
            || tet->g_tet->map[y + 1][x] == '*')) {
                transfert_tetri(tet);
                return (TRUE);
            }
            x = x + 1;
        }
        x = 0;
        y = y - 1;
    }
    return (FALSE);
}

void go_down(tetris_t *tet)
{
    int x = 0;
    int y = tet->fl->height - 2;

    if (verif_go_down(tet) == TRUE)
        return;
    while (y >= 0) {
        while (x < tet->fl->width) {
            if (tet->g_tet->tetr[y][x] == '*'
            && tet->g_tet->tetr[y + 1][x] == ' ') {
                tet->g_tet->tetr[y + 1][x] = '*';
                tet->g_tet->tetr[y][x] = ' ';
            }
            x = x + 1;
        }
        x = 0;
        y = y - 1;
    }
}