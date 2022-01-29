/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** stock_tetrimino
*/

#include "../../tetris.h"

char *take_name(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '.')
        i = i + 1;
    str[i] = '\0';
    return (str);
}

rlist *init_tetriminos(rlist *p_list, char *filepath)
{
    struct node *nd;
    static int i = 0;

    if (i == 0) {
        nd = init_node(filepath);
        if (nd == NULL)
            return (NULL);
        p_list = dlist_new(nd);
        if (p_list == NULL)
            return (NULL);
        i = 1;
    } else {
        nd = add_node_end(filepath, p_list->p_tail);
        if (nd == NULL)
            return (NULL);
        add_element(nd, p_list);
    }
    return (p_list);
}

int verif_name_tetrimino(char *name)
{
    char *tetri = "tetrimino";
    int i = 0;
    int a = 0;

    if (my_strlen(name) < 10)
        return (FALSE);
    while (name[i] != '\0' && name[i] != '.')
        i = i + 1;
    if (name[i] == '\0')
        return (FALSE);
    i = i + 1;
    while (tetri[a] != '\0' && name[i] != '\0' && name[i] == tetri[a]) {
        a = a + 1;
        i = i + 1;
        if (name[i] != tetri[a])
            return (FALSE);
    }
    if (tetri[a] != '\0' || name[i] != '\0')
        return (FALSE);
    return (TRUE);
}

int add_tetriminos(struct dirent *sd, tetris_t *tet)
{
    if (verif_name_tetrimino(sd->d_name) == TRUE && sd->d_type == 8) {
        tet->p_list = init_tetriminos(tet->p_list, sd->d_name);
        if (tet->p_list == NULL)
            return (ERROR);
        return (ISSUE);
    }
    return (SUCCESS);
}

int stock_tetriminos(tetris_t *tet)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *sd;
    int i = 0;
    int a = 0;

    if (dir == NULL)
        return (ERROR);
    while ((sd = readdir(dir)) != NULL) {
        i = add_tetriminos(sd, tet);
        if (i == ERROR)
            return (ERROR);
        else if (i == ISSUE)
            a = a + 1;
    }
    closedir(dir);
    if (a == 0)
        exit(0);
    return (SUCCESS);
}