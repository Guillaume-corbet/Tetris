/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** display_debug
*/

#include "../../tetris.h"

void display_command(command_t *com)
{
    verif_key(K_LEFT, com->left);
    verif_key(K_RIGHT, com->right);
    verif_key(K_TURN, com->turn);
    verif_key(K_DROP, com->drop);
    verif_key(K_QUIT, com->quit);
    verif_key(K_PAUSE, com->pause);
}

void display_flag(flags_t *fl)
{
    if (fl->next == 0)
        my_printf("%sYes\n", NEXT);
    else
        my_printf("%sNo\n", NEXT);
    my_printf("%s%d\n", LEVEL, fl->level);
    my_printf("%s%d*%d\n", SIZE, fl->height, fl->width);
}

void display_number_tetriminos(size_t length)
{
    int i = 0;

    while (length > 0) {
        i = i + 1;
        length = length - 1;
    }
    my_printf("%s%d\n", TETRI, i);
}

void display_tetrimino(rlist *p_list)
{
    struct node *tmp = p_list->p_head;

    display_number_tetriminos(p_list->length);
    while (tmp) {
        if (tmp->tetri->error == 1) {
            my_printf("%s%s%s%s", TETRI, NAME, tmp->tetri->name, ERROR_TET);
        } else {
            my_printf("%s%s%s%s", TETRI, NAME, tmp->tetri->name, SIZES);
            my_printf("%d*%d", tmp->tetri->width, tmp->tetri->height);
            my_printf("%s%d :\n", COLOR, tmp->tetri->color);
            display_tab(tmp->tetri->tetrimino);
        }
        tmp = tmp->p_next;
    }
}

void display_debug(tetris_t *tet)
{
    my_putstr(DEBUG_MODE);
    display_command(tet->com);
    display_flag(tet->fl);
    display_tetrimino(tet->p_list);
    my_putstr("Press any key to starts Tetris\n");
}