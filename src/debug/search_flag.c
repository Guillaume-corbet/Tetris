/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** search_flag
*/

#include "../../tetris.h"

int search_flags(int argc, char **argv, char *flag)
{
    int i = 0;

    while (i < argc) {
        if (argv[i + 1] != NULL && my_strcmp(flag, "-L") == 0
        && my_strcmp(argv[i], flag) == 0)
            return (my_getnbr(argv[i + 1]));
        if (my_strcmp(argv[i], flag) == 0)
            return (TRUE);
        i = i + 1;
    }
    return (FALSE);
}

int search_flags_long(int argc, char **argv, char *flag)
{
    int i = 0;

    while (i < argc) {
        if (my_strcmp(flag, "--level=") == 0
        && my_strncmp(argv[i], flag, my_strlen(flag)) == 0) {
            return (get_lvl(argv[i]));
        }
        if (my_strncmp(argv[i], flag, my_strlen(flag)) == 0)
            return (TRUE);
        i = i + 1;
    }
    return (FALSE);
}