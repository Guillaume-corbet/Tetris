/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** search_key
*/

#include "../../tetris.h"

void verif_key(char *str, char c)
{
    if (c == 'A')
        my_printf("%s%s\n", str, EOA);
    else if (c == 'B')
        my_printf("%s%s\n", str, EOB);
    else if (c == 'C')
        my_printf("%s%s\n", str, EOC);
    else if (c == 'D')
        my_printf("%s%s\n", str, EOD);
    else if (c == ' ')
        my_printf("%s%s\n", str, SPACE);
    else
        my_printf("%s%c\n", str, c);
}

char search_key(int argc, char **argv, char *search)
{
    int i = 0;

    while (i < argc) {
        if (argv[i + 1] != NULL && my_strcmp(argv[i], search) == 0)
            return (argv[i + 1][0]);
        i = i + 1;
    }
    return (FALSE);
}

char search_long_key(int argc, char **argv, char *search)
{
    int i = 0;

    while (i < argc) {
        if (my_strncmp(argv[i], search, my_strlen(search)) == 0)
            return (argv[i][my_strlen(search)]);
        i = i + 1;
    }
    return (FALSE);
}