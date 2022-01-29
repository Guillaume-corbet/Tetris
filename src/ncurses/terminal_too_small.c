/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** terminal_too_small
*/

#include "../../tetris.h"

void terminal_too_small(tetris_t *tet)
{
    int a = 0;

    if (LINES < tet->fl->height + 10 || COLS < (tet->fl->width * 3 + 20)) {
        clear();
        a = 1;
    }
    while (1) {
        refresh();
        if (LINES < tet->fl->height + 10 || COLS < (tet->fl->width * 3 + 20)) {
            mvprintw(0, 0, "Terminal too small");
        } else if (a == 1){
            clear();
            break;
        } else
            break;
    }
}