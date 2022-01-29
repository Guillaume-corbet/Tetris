/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** main
*/

#include "../../tetris.h"

char *int_to_str(int nb)
{
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * 11);
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    while (nb > 0) {
        str[a] = (nb % 10) + 48;
	    nb = nb / 10;
	    a = a + 1;
    }
    str[a] = '\0';
    str = my_revstr(str);
    return (str);
}

int count_length(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

int main(int argc, char **argv)
{
    tetris_t *tet;

    if (argc > 1 && my_strcmp("--help", argv[1]) == 0) {
        help(argc, argv);
        return (0);
    }
    if ((tet = init_all_tetris(argc, argv)) == NULL)
        return (ERROR);
    if (tet->fl->debug == 1) {
        display_debug(tet);
        if (game(tet) == ERROR)
            return (ERROR);
    } else {
        if (game(tet) == ERROR)
            return (ERROR);
    }
    free_all(tet);
    return (SUCCESS);
}