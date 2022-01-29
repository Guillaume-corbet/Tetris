/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** display_linked_list
*/

#include "../../tetris.h"

void display_linked(tetris_t *tet)
{
    struct node *tmp = tet->p_list->p_head;

    while (tmp) {
        my_putstr(tmp->tetri->name);
        my_putchar('\n');
        tmp = tmp->p_next;
        if (tmp == NULL)
            my_putstr("null\n");
    }
    my_putstr("end\n\n");
}