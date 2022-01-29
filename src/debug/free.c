/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** free
*/

#include "../../tetris.h"

void free_linked_list(rlist **p_list)
{
    struct node *tmp = (*p_list)->p_head;
    struct node *del;

    while (tmp) {
        del = tmp;
        tmp = tmp->p_next;
        free_struct_tetrimino(del->tetri);
        free(del);
    }
    free(*p_list);
    *p_list = NULL;
}

void free_struct_game(g_tetris_t *g_tet)
{
    free_tab(g_tet->map);
    free_tab(g_tet->tetr);
    free(g_tet);
}

void free_all(tetris_t *tet)
{
    free(tet->com);
    free(tet->fl);
    free_struct_game(tet->g_tet);
    free_linked_list(&tet->p_list);
    free(tet);
}

void free_struct_tetrimino(tetrimino_t *tetri)
{
    free(tetri->name);
    free_tab(tetri->tetrimino);
    free(tetri);
}