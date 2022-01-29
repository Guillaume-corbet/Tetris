/*
** EPITECH PROJECT, 2019
** PSU_tetris2_2018
** File description:
** help_tab
*/

#include "my.h"

void display_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i = i + 1;
    }
}

int length_tab(char **tab)
{
    int x = 0;

    while (tab[x] != NULL) {
        x = x + 1;
    }
    return (x);
}