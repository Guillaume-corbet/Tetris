/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** time
*/

#include "../../tetris.h"

void wait_before_start(tetris_t *tet)
{
    struct termios info;

    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;
    info.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &info);
    getchar();
}

void clock_down(tetris_t *tet, clock_t start)
{
    clock_t now = clock();
    int seconds = now - start;
    int result = 10000 * tet->fl->level;

    if ((seconds % 1000000) < 50)
        tet->g_tet->seconds = tet->g_tet->seconds + 1;
    result = 200000 - result;
    if ((seconds % result) < 50)
        go_down(tet);
    if (tet->g_tet->seconds >= 60) {
        tet->g_tet->seconds = 0;
        tet->g_tet->minutes = tet->g_tet->minutes + 1;
    }
}