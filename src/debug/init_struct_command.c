/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_struct_command
*/

#include "../../tetris.h"

void init_struct_command_first(int argc, char **argv, command_t *com)
{
    if ((com->left = search_key(argc, argv, "-l")) == 0) {
        if ((com->left = search_long_key(argc, argv, "--key-left=")) == 0)
            com->left = 'D';
    }
    com->drop = search_key(argc, argv, "-d");
    if (com->drop == 0) {
        if ((com->drop = search_long_key(argc, argv, "--key-drop=")) == 0)
            com->drop = 'B';
    }
    com->right = search_key(argc, argv, "-r");
    if (com->right == 0) {
        if ((com->right = search_long_key(argc, argv, "--key-right=")) == 0)
            com->right = 'C';
    }
}

void init_struct_command_second(int argc, char **argv, command_t *com)
{
    com->turn = search_key(argc, argv, "-t");
    if (com->turn == 0) {
        if ((com->turn = search_long_key(argc, argv, "--key-turn=")) == 0)
            com->turn = 'A';
    }
    if ((com->pause = search_key(argc, argv, "-p")) == 0) {
        if ((com->pause = search_long_key(argc, argv, "--key-pause=")) == 0)
            com->pause = ' ';
    }
    com->quit = search_key(argc, argv, "-q");
    if (com->quit == 0) {
        if ((com->quit = search_long_key(argc, argv, "--key-quit=")) == 0)
            com->quit = 'q';
    }
}

command_t *init_struct_command(int argc, char **argv)
{
    command_t *com;

    if ((com = malloc(sizeof(command_t))) == NULL)
        return (NULL);
    init_struct_command_first(argc, argv, com);
    init_struct_command_second(argc, argv, com);
    return (com);
}