/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** display_next
*/

#include "../../tetris.h"

void display_next_tetri(flags_t *fl, g_tetris_t *g_tet)
{
    int i = 0;

    while (g_tet->next->tetri->tetrimino[i] != NULL) {
        mvprintw(i + 6, 27 + fl->width, g_tet->next->tetri->tetrimino[i]);
        i = i + 1;
    }
}

void display_next_map(flags_t *fl, g_tetris_t *g_tet)
{
    int i = 1;

    mvprintw(5, 26 + fl->width, "+");
    while (i < 6) {
        mvprintw(5, 26 + i + fl->width, "-");
        i = i + 1;
    }
    mvprintw(5, 26 + i + fl->width, "+");
    mvprintw(5 + 6, 26 + i + fl->width, "+");
    i = i - 1;
    while (i > 0) {
        mvprintw(5 + 6, 26 + i + fl->width, "-");
        i = i - 1;
    }
    mvprintw(5 + 6, 26 + fl->width, "+");
    while (i < 5) {
        mvprintw(6 + i, 26 + fl->width, "|");
        mvprintw(6 + i, 26 + fl->width + 6, "|");
        i = i + 1;
    }
    display_next_tetri(fl, g_tet);
}