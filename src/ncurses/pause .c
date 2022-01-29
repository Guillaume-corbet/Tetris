/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** pause 
*/

#include "../../tetris.h"

int pause_menu(tetris_t *tet)
{
    int ch = getch();

    mvprintw(0, COLS / 2 - 14, "PAUSE press again to continue");
    while (ch != tet->com->pause) {
        ch = getch();
        if (ch == tet->com->quit)
            return (42);
    }
    clear();
    return (0);
}