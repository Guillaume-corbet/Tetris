/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_struct_tetrimino
*/

#include "../../tetris.h"

int take_tetrimino(tetrimino_t *tetri, FILE *fd, char *filepath, char *str)
{
    int i = 0;
    size_t bufs = 100;

    if ((tetri->name = malloc(sizeof(char) * my_strlen(filepath) + 1)) == NULL)
        return (84);
    filepath = take_name(filepath);
    tetri->name = my_strcpy(tetri->name, filepath);
    if ((tetri->tetrimino = malloc(sizeof(char *) * 100)) == NULL)
        return (84);
    while (getline(&str, &bufs, fd) != -1) {
        if ((tetri->tetrimino[i] = malloc(sizeof(char) * 100)) == NULL)
            return (84);
        tetri->tetrimino[i] = my_strcpy(tetri->tetrimino[i], str);
        if (tetri->tetrimino[i][my_strlen(str) - 1] == '\n')
            tetri->tetrimino[i][my_strlen(str) - 1] = '\0';
        i = i + 1;
    }
    tetri->tetrimino[i] = NULL;
    if (fclose(fd) == -1)
        return (84);
    return (0);
}

tetrimino_t *init_struct_tetrimino(char *filepath)
{
    tetrimino_t *tetri;
    FILE *fd;
    size_t bufs = 100;
    char *str;

    if ((str = malloc(sizeof(char) * 1000)) == NULL)
        return (NULL);
    chdir("tetriminos");
    if ((fd = fopen(filepath, "r")) == NULL)
        return (NULL);
    chdir("..");
    if ((tetri = malloc(sizeof(tetrimino_t))) == NULL)
        return (NULL);
    getline(&str, &bufs, fd);
    if (get_element_tetri(tetri, str) == ERROR)
        return (NULL);
    if (take_tetrimino(tetri, fd, filepath, str) == ERROR)
        return (NULL);
    free(str);
    tetri->error = 0;
    return (tetri);
}