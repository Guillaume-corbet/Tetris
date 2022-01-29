/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_map
*/

#include "../../tetris.h"

char *init_str_map(flags_t *fl)
{
    char *str;
    int i = 0;
    int length = fl->width;

    if ((str = malloc(sizeof(char) * (length + 1))) == NULL)
        return (NULL);
    while (i < length) {
        str[i] = ' ';
        i = i + 1;
    }
    str[i] = '\0';
    return (str);
}

char **init_map(flags_t *fl)
{
    char **tab;
    int i = 0;

    if ((tab = malloc(sizeof(char *) * (fl->height + 1))) == NULL)
        return (NULL);
    while (i < fl->height) {
        if ((tab[i] = init_str_map(fl)) == NULL)
            return (NULL);
        i = i + 1;
    }
    tab[fl->height] = NULL;
    return (tab);
}