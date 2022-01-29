/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** add_tetri
*/

#include "../../tetris.h"

struct node *random_tetrimino(tetris_t *tet)
{
    struct node *tmp = tet->p_list->p_head;
    int x = rand()%tet->p_list->length + 1;

    while (x > 1) {
        tmp = tmp->p_next;
        x = x - 1;
    }
    while (tmp->tetri->error == 1) {
        tmp = tet->p_list->p_head;
        x = rand()%tet->p_list->length;
        while (x > 1) {
            tmp = tmp->p_next;
            x = x - 1;
        }
    }
    return (tmp);
}

int add_tetri_map_first(tetris_t *tet)
{
    int length = tet->fl->width;
    int a = 0;
    int x = 0;
    int y = 0;
    struct node *tmp = random_tetrimino(tet);

    length = length - tmp->tetri->width + 1;
    a = rand()%length;
    while (y < tmp->tetri->height) {
        while (x < tmp->tetri->width) {
            if (tet->g_tet->map[y][x + a] == '*')
                return (84);
            tet->g_tet->tetr[y][x + a] = tmp->tetri->tetrimino[y][x];
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
    tet->g_tet->next = random_tetrimino(tet);
    return (0);
}

int add_tetri_map_second(tetris_t *tet)
{
    int length = tet->fl->width;
    int a = 0;
    int x = 0;
    int y = 0;

    length = length - tet->g_tet->next->tetri->width + 1;
    a = rand()%length;
    while (y < tet->g_tet->next->tetri->height) {
        while (x < tet->g_tet->next->tetri->width) {
            if (tet->g_tet->map[y][x + a] == '*')
                return (84);
            tet->g_tet->tetr[y][x + a]
            = tet->g_tet->next->tetri->tetrimino[y][x];
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
    tet->g_tet->next = random_tetrimino(tet);
    return (0);
}

int check_stars_tetri(tetris_t *tet)
{
    int x = 0;
    int y = 0;

    while (y < tet->fl->height) {
        while (x < tet->fl->width) {
            if (tet->g_tet->tetr[y][x] == '*')
                return (1);
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
    return (0);
}