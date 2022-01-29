/*
** EPITECH PROJECT, 2019
** PSU_tetris2_2018
** File description:
** fill_str
*/

#include "my.h"

char *fill_str(char *str, int x)
{
    int i = 0;

    while (i < x) {
        str[i] = '\0';
        i = i + 1;
    }
    return (str);
}