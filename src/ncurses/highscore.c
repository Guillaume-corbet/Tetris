/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** highscore
*/

#include "../../tetris.h"

int write_highscore(tetris_t *tet)
{
    int fd = open("highscore", O_RDWR);
    char *str = int_to_str(tet->g_tet->score);

    write(fd, str, my_strlen(str));
    close(fd);
    return (0);
}

int read_highscore(tetris_t *tet)
{
    int fd = 0;
    char *str = malloc(sizeof(char) * 11);
    int charac = 0;

    if (str == NULL)
        return (-84);
    if ((fd = open("highscore", O_RDWR)) == -1)
        return (-84);
    str[10] = '\0';
    if ((charac = read(fd, str, 10)) == -1)
        return (-84);
    str[charac] = '\0';
    if (close(fd) == -1)
        return (-84);
    charac = my_getnbr(str);
    free(str);
    return (charac);
}