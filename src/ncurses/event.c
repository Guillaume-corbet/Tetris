/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** event
*/

#include "../../tetris.h"

int event(tetris_t *tet, clock_t start)
{
    int ch = 0;

    ch = getch();
    if (ch == tet->com->quit)
        return (42);
    else if (ch == tet->com->left)
        go_left(tet);
    else if (ch == tet->com->right)
        go_right(tet);
    else if (ch == tet->com->pause) {
        if (pause_menu(tet) == 42)
            return (42);
    } else if (ch == tet->com->drop)
        go_down(tet);
    return (0);
}