/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** line_full
*/

#include "../../tetris.h"

void go_down_line_full(tetris_t *tet)
{
    int a = count_length(tet->g_tet->map[0]) - 1;
    int x = count_length(tet->g_tet->map[0]) - 1;
    int y = length_tab(tet->g_tet->map) - 1;

    while (y >= 0) {
        while (x >= 0) {
            if (tet->g_tet->map[y + 1] == NULL)
                y = y - 1;
            if (tet->g_tet->map[y + 1] != NULL
            && tet->g_tet->map[y][x] == '*') {
                if (tet->g_tet->map[y + 1][x] == ' ') {
                    tet->g_tet->map[y][x] = ' ';
                    tet->g_tet->map[y + 1][x] = '*';
                }
            }
            x = x - 1;
        }
        x = a;
        y = y - 1;
    }
}

void supress_line_full(tetris_t *tet, int y)
{
    int i = 0;

    while (tet->g_tet->map[y][i] != '\0') {
        tet->g_tet->map[y][i] = ' ';
        tet->g_tet->score = tet->g_tet->score + 10;
        i = i + 1;
    }
}

void verif_line_full(tetris_t *tet)
{
    int i = 0;
    int count = 0;
    int y = tet->fl->height - 1;

    while (y > 0) {
        while (tet->g_tet->map[y][i] != '\0') {
            if (tet->g_tet->map[y][i] == ' ' && tet->g_tet->map[y][i] != '\0')
                count = 1;
            i = i + 1;
        }
        if (count == 0) {
            supress_line_full(tet, y);
            tet->g_tet->lines = tet->g_tet->lines + 1;
            if ((tet->g_tet->lines % 10) == 0)
                tet->fl->level = tet->fl->level + 1;
            go_down_line_full(tet);
        }
        y = y - 1;
        count = 0;
        i = 0;
    }
}