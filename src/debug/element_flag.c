/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** element_flag
*/

#include "../../tetris.h"

int get_lvl(char *str)
{
    char number[my_strlen(str)];
    int i = 0;
    int a = 0;

    while (str[i] != '=')
        i = i + 1;
    i = i + 1;
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        number[a] = str[i];
        a = a + 1;
        i = i + 1;
    }
    number[a] = '\0';
    return (my_getnbr(number));
}

int get_width(char *str)
{
    char number[my_strlen(str)];
    int i = 0;
    int a = 0;

    while (str[i] != '=')
        i = i + 1;
    i = i + 1;
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
        i = i + 1;
    i = i + 1;
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        number[a] = str[i];
        a = a + 1;
        i = i + 1;
    }
    number[a] = '\0';
    return (my_getnbr(number));
}

int search_height(int argc, char **argv)
{
    int i = 0;

    while (i < argc) {
        if (my_strncmp(argv[i], "--map-size=", my_strlen("--map-size=")) == 0)
            return (get_lvl(argv[i]));
        i = i + 1;
    }
    return (FALSE);
}

int search_width(int argc, char **argv)
{
    int i = 0;

    while (i < argc) {
        if (my_strncmp(argv[i], "--map-size=", my_strlen("--map-size=")) == 0)
            return (get_width(argv[i]));
        i = i + 1;
    }
    return (FALSE);
}