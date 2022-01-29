/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_struct_flag
*/

#include "../../tetris.h"

flags_t *init_struct_flags(int argc, char **argv)
{
    flags_t *fl;

    if ((fl = malloc(sizeof(flags_t))) == NULL)
        return (NULL);
    if ((fl->next = search_flags(argc, argv, "-w")) == 0)
        fl->next = search_flags_long(argc, argv, "--without-next");
    fl->debug = search_flags(argc, argv, "-D");
    if (fl->debug == 0)
        fl->debug = search_flags_long(argc, argv, "--debug");
    fl->level = search_flags(argc, argv, "-L");
    if (fl->level == 0) {
        if ((fl->level = search_flags_long(argc, argv, "--level=")) == 0)
            fl->level = 1;
    }
    fl->height = search_height(argc, argv);
    if (fl->height == 0) {
        fl->height = 20;
        fl->width = 10;
    } else
        fl->width = search_width(argc, argv);
    return (fl);
}