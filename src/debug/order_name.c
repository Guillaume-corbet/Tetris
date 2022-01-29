/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** order_name
*/

#include "../../tetris.h"

int strcmp_name(struct node *tmp)
{
    int i = 0;

    while (tmp->tetri->name[i] != '\0' && tmp->p_next->tetri->name[i] != '\0') {
        if (tmp->tetri->name[i] < tmp->p_next->tetri->name[i])
            return (FALSE);
        else if (tmp->tetri->name[i] > tmp->p_next->tetri->name[i])
            return (TRUE);
        i = i + 1;
    }
    if (tmp->p_next->tetri->name[i] == '\0')
        return (TRUE);
    return (FALSE);
}

void change_pointer(struct node *tmp)
{
    tetrimino_t *tetri = tmp->tetri;

    tmp->tetri = tmp->p_next->tetri;
    tmp->p_next->tetri = tetri;
}

int put_order_name_sec(tetris_t *tet)
{
    int change = 0;
    struct node *tmp = tet->p_list->p_head;

    while (tmp->p_next) {
        if (strcmp_name(tmp) == TRUE) {
            change_pointer(tmp);
            change = 1;
        }
        tmp = tmp->p_next;
    }
    return (change);
}

int put_order_name(tetris_t *tet)
{
    int change = 1;

    while (change != 0) {
        change = 0;
        if (put_order_name_sec(tet) > 0) {
            change = 1;
        }
    }
    return (SUCCESS);
}