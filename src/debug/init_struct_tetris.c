/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_struct_tetris
*/

#include "../../tetris.h"

g_tetris_t *init_struct_game_tetris(tetris_t *tet)
{
    g_tetris_t *g_tet = malloc(sizeof(g_tetris_t));

    if (g_tet == NULL)
        return (NULL);
    g_tet->score = 0;
    g_tet->lines = 0;
    g_tet->minutes = 0;
    g_tet->seconds = 0;
    if ((g_tet->highscore = read_highscore(tet)) == -84)
        return (NULL);
    return (g_tet);
}

tetris_t *init_struct_tetris(int argc, char **argv)
{
    tetris_t *tet;

    if ((tet = malloc(sizeof(tetris_t))) == NULL)
        return (NULL);
    if ((tet->com = init_struct_command(argc, argv)) == NULL)
        return (NULL);
    tet->fl = init_struct_flags(argc, argv);
    if (tet->fl == NULL)
        return (NULL);
    if (stock_tetriminos(tet) == ERROR)
        return (NULL);
    tet->g_tet = init_struct_game_tetris(tet);
    if (tet->g_tet == NULL)
        return (NULL);
    return (tet);
}

tetris_t *init_all_tetris(int argc, char **argv)
{
    tetris_t *tet;

    if ((tet = init_struct_tetris(argc, argv)) == NULL)
        return (NULL);
    if (put_order_name(tet) == ERROR)
        return (NULL);
    verif_tetrimino(tet);
    return (tet);
}