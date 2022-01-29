/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** add_to_list
*/

#include "../../tetris.h"

rlist *dlist_new(struct node *new)
{
    rlist *p_new = malloc(sizeof(rlist));
    if (p_new == NULL)
        return (NULL);
    if (p_new != NULL) {
        p_new->length = 1;
        p_new->p_head = new;
        p_new->p_tail = new;
    }
    return (p_new);
}

struct node *init_node(char *filepath)
{
    struct node *new = malloc(sizeof(struct node));

    if (new == NULL)
        return (NULL);
    new->tetri = init_struct_tetrimino(filepath);
    if (new->tetri == NULL)
        return (NULL);
    new->p_next = NULL;
    new->p_prev = NULL;
    return (new);
}

struct node *add_node_end(char *filepath, struct node *old)
{
    struct node *new = malloc(sizeof(struct node));

    if (new == NULL)
        return (NULL);
    new->tetri = init_struct_tetrimino(filepath);
    if (new->tetri == NULL)
        return (NULL);
    new->p_next = NULL;
    new->p_prev = old;
    old->p_next = new;
    return (new);
}

void add_element(struct node *new, rlist *p_list)
{
    p_list->p_tail = new;
    p_list->length = p_list->length + 1;
}

rlist *remove_element(rlist *p_list, struct node *tmp)
{
    if (tmp->p_next == NULL) {
        p_list->p_tail = tmp->p_prev;
        p_list->p_tail->p_next = NULL;
    } else if (tmp->p_prev == NULL) {
        p_list->p_head = tmp->p_next;
        p_list->p_head->p_prev = NULL;
    } else {
        tmp->p_next->p_prev = tmp->p_prev;
        tmp->p_prev->p_next = tmp->p_next;
    }
    free_struct_tetrimino(tmp->tetri);
    free(tmp);
    p_list->length = p_list->length - 1;
    return (p_list);
}