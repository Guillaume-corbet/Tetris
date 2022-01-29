/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game
*/

#include "../../tetris.h"

int start_game(tetris_t *tet)
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    clear();
    srand(time(NULL));
    tet->g_tet->map = init_map(tet->fl);
    tet->g_tet->tetr = init_map(tet->fl);
    if (tet->g_tet->map == NULL)
        return (ERROR);
    add_tetri_map_first(tet);
    curs_set(0);
    return (0);
}

void end_game(tetris_t *tet)
{
    if (tet->g_tet->score > tet->g_tet->highscore) {
        write_highscore(tet);
    }
}

void space_on_next(tetris_t *tet)
{
    int y = 0;

    while (y < 6) {
        mvprintw(6 + y, 26 + tet->fl->width, "     ");
        y = y + 1;
    }
}

int check_tetri_low(tetris_t *tet)
{
    if (check_stars_tetri(tet) == 0) {
        space_on_next(tet);
        if (add_tetri_map_second(tet) == 84) {
            end_game(tet);
            return (42);
        }
    }
    return (0);
}

int game(tetris_t *tet)
{
    clock_t start = clock();

    if (start_game(tet) == ERROR)
        return (ERROR);
    while (1) {
        terminal_too_small(tet);
        clock_down(tet, start);
        if (check_tetri_low(tet) == 42)
            break;
        verif_line_full(tet);
        display_ncurses(tet->fl, tet->g_tet);
        if (event(tet, start) == 42)
            break;
        refresh();
    }
    endwin();
    return (0);
}