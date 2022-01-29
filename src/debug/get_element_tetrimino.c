/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** get_element_tetrimino
*/

#include "../../tetris.h"

char *width_tetrimino(char *str)
{
    int i = 0;
    int a = 0;
    char *number;

    if ((number = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
        return (NULL);
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        number[a] = str[i];
        i = i + 1;
        a = a + 1;
    }
    number[a] = '\0';
    return (number);
}

char *height_tetrimino(char *str)
{
    int i = 0;
    int a = 0;
    char *number;

    if ((number = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
        return (NULL);
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        i = i + 1;
    i = i + 1;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        number[a] = str[i];
        i = i + 1;
        a = a + 1;
    }
    number[a] = '\0';
    return (number);
}

char *color_tetrimino(char *str)
{
    int i = 0;
    int a = 0;
    char *number;

    if ((number = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
        return (NULL);
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        i = i + 1;
    i = i + 1;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        i = i + 1;
    i = i + 1;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        number[a] = str[i];
        i = i + 1;
        a = a + 1;
    }
    number[a] = '\0';
    return (number);
}

int get_element_tetri(tetrimino_t *tetri, char *str)
{
    char *number;

    if ((number = height_tetrimino(str)) == NULL)
        return (ERROR);
    tetri->height = my_getnbr(number);
    free(number);
    if ((number = width_tetrimino(str)) == NULL)
        return (ERROR);
    tetri->width = my_getnbr(number);
    free(number);
    if ((number = color_tetrimino(str)) == NULL)
        return (ERROR);
    tetri->color = my_getnbr(number);
    free(number);
    return (SUCCESS);
}