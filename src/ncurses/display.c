/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** display
*/

#include "../../tetris.h"

void display_first_line(flags_t *fl, int a)
{
    int i = 21;

    if (a == 0) {
        mvprintw(2, 20, "+");
        while (i < fl->width + 23) {
            mvprintw(2, i, "-");
            i = i + 1;
        }
        mvprintw(2, i, "+");
    } else {
        mvprintw(fl->height + 3, 20, "+");
        while (i < fl->width + 23) {
            mvprintw(fl->height + 3, i, "-");
            i = i + 1;
        }
        mvprintw(fl->height + 3, i, "+");
    }
}

void display_map(flags_t *fl, g_tetris_t *g_tet)
{
    int x = 0;
    int y = 0;

    while (y < fl->height) {
        mvprintw(3 + y, 20, "| ");
        while (x < fl->width) {
            if (g_tet->map[y][x] == '*' || g_tet->tetr[y][x] == '*')
                mvprintw(3 + y, 22 + x, "*");
            else
                mvprintw(3 + y, 22 + x, " ");
            x = x + 1;
        }
        mvprintw(3 + y, 22 + x, " |");
        x = 0;
        y = y + 1;
    }
}

void display_info_second(flags_t *fl, g_tetris_t *g_tet)
{
    char *str;

    if (g_tet->seconds < 10)
        mvprintw(LINES / 2 + 4, 8, " ");
    str = int_to_str(g_tet->seconds);
    mvprintw(LINES / 2 + 4, 7, str);
    free(str);
    mvprintw(LINES / 2 + 5, 5, "LINES");
    str = int_to_str(g_tet->lines);
    mvprintw(LINES / 2 + 6, 5, str);
    free(str);
    mvprintw(LINES / 2 + 7, 5, "LEVEL");
    str = int_to_str(fl->level);
    mvprintw(LINES / 2 + 8, 6, str);
    free(str);
}

void display_info_first(flags_t *fl, g_tetris_t *g_tet)
{
    char *str;

    mvprintw(LINES / 2 - 1, 5, "SCORE");
    str = int_to_str(g_tet->score);
    mvprintw(LINES / 2 , 5, str);
    free(str);
    mvprintw(LINES / 2 + 1, 5, "HIGHSCORE");
    str = int_to_str(g_tet->highscore);
    mvprintw(LINES / 2 + 2, 5, str);
    free(str);
    mvprintw(LINES / 2 + 3, 5, "TIMER");
    str = int_to_str(g_tet->minutes);
    mvprintw(LINES / 2 + 4, 5, str);
    free(str);
    display_info_second(fl, g_tet);
}

void display_ncurses(flags_t *fl, g_tetris_t *g_tet)
{
    display_first_line(fl, 0);
    display_map(fl, g_tet);
    display_first_line(fl, 1);
    display_info_first(fl, g_tet);
    if (fl->next == 0)
        display_next_map(fl, g_tet);
}