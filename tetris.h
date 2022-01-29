/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <ncurses.h>
#include <termios.h>
#include "lib/my/my.h"
#include "lib/my_printf/my_printf.h"

#define DEBUG_MODE "*** DEBUG MODE ***\n"
#define K_LEFT "Key Left :  "
#define K_RIGHT "Key Right :  "
#define K_TURN "Key Turn :  "
#define K_DROP "Key Drop :  "
#define K_QUIT "Key Quit :  "
#define K_PAUSE "Key Pause :  "
#define NEXT "Next :  "
#define LEVEL "Level :  "
#define SIZE "Size :  "
#define SPACE "(space)"
#define EOA "^EOA"
#define EOB "^EOB"
#define EOC "^EOC"
#define EOD "^EOD"
#define TETRI "Tetriminos :  "
#define NAME "Name "
#define SIZES " :  Size "
#define COLOR " :  Color "
#define ERROR_TET " :  Error\n"
#define HELP "Usage: %s [options]\nOptions:\n --help \t\tDispl\
ay this help\n -L --level={num} \tStart Tetris at level num (def: 1)\n -l --\
key-left={K} \tMove the tetrimino LEFT using the K key (def: left arrow)\n -\
r --key-right={K} \tMove the tetrimino RIGHT using the K key (def: righ\
t arrow)\n -t --key-turn={K} \tTURN the tetrimino clockwise 90d using the K k\
ey (def: top arrow)\n -d --key-drop={K} \tDROP the tetrimino using th\
e K key (def: down arrow)\n -q --key-quit={K} \tQUIT the game using the K ke\
y (def: ‘q’ key)\n -p --key-pause={K} \tPAUSE/RESTART the game using the K k\
ey (def: space bar)\n --map-size={row,col} \tSet the numbers of rows and colu\
mns of the map (def: 20,10)\n -w --without-next \tHide next tetrimi\
no (def: false)\n -D --debug \t\tDebug mode (def: false)\n"

#define SUCCESS (0)
#define ERROR (84)
#define ISSUE (1)

typedef struct tetrimino
{
    char *name;
    char **tetrimino;
    int height;
    int width;
    int color;
    int error;
}tetrimino_t;

struct node
{
    tetrimino_t *tetri;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
}rlist;

typedef struct command
{
    char left;
    char right;
    char turn;
    char drop;
    char quit;
    char pause;
}command_t;

typedef struct flags
{
    int next;
    int level;
    int height;
    int width;
    int debug;
}flags_t;

typedef struct g_tetris
{
    char **map;
    char **tetr;
    int score;
    int highscore;
    int seconds;
    int minutes;
    int lines;
    struct node *next;
}g_tetris_t;

typedef struct tetris
{
    command_t *com;
    flags_t *fl;
    g_tetris_t *g_tet;
    rlist *p_list;
}tetris_t;

#ifndef INC_
#define INC_

/* order_name.c */

int strcmp_name(struct node *tmp);
void change_pointer(struct node *tmp);
int put_order_name_sec(tetris_t *tet);
int put_order_name(tetris_t *tet);

/* free.c */

void free_linked_list(rlist **p_list);
void free_struct_game(g_tetris_t *g_tet);
void free_all(tetris_t *tet);
void free_struct_tetrimino(tetrimino_t *tetri);

/* init_struct_command.c */

void init_struct_command_first(int argc, char **argv, command_t *com);
void init_struct_command_second(int argc, char **argv, command_t *com);
command_t *init_struct_command(int argc, char **argv);

/* display_debug.c */

void display_command(command_t *com);
void display_flag(flags_t *fl);
void display_number_tetriminos(size_t length);
void display_tetrimino(rlist *p_list);
void display_debug(tetris_t *tet);

/* add_to_list.c */

rlist *dlist_new(struct node *new);
struct node *init_node(char *filepath);
struct node *add_node_end(char *filepath, struct node *old);
void add_element(struct node *new, rlist *p_list);
rlist *remove_element(rlist *p_list, struct node *tmp);

/* verif_tetrimino_sec.c */

int verif_tetrimino_five(char verif);
void verif_tetrimino_four(tetris_t *tet, struct node *tmp);

/* init_struct_tetris.c */

g_tetris_t *init_struct_game_tetris(tetris_t *tet);
tetris_t *init_struct_tetris(int argc, char **argv);
tetris_t *init_all_tetris(int argc, char **argv);

/* element_flag.c */

int get_lvl(char *str);
int get_width(char *str);
int search_height(int argc, char **argv);
int search_width(int argc, char **argv);

/* search_key.c */

void verif_key(char *str, char c);
char search_key(int argc, char **argv, char *search);
char search_long_key(int argc, char **argv, char *search);

/* search_flag.c */

int search_flags(int argc, char **argv, char *flag);
int search_flags_long(int argc, char **argv, char *flag);

/* verif_tetrimino.c */

void verif_tetrimino_third(tetris_t *tet, struct node *tmp);
void verif_tetrimino_sec(tetris_t *tet);
void verif_tetrimino(tetris_t *tet);

/* init_struct_flag.c */

flags_t *init_struct_flags(int argc, char **argv);

/* display_linked_list.c */

void display_linked(tetris_t *tet);

/* get_element_tetrimino.c */

char *width_tetrimino(char *str);
char *height_tetrimino(char *str);
char *color_tetrimino(char *str);
int get_element_tetri(tetrimino_t *tetri, char *str);

/* init_struct_tetrimino.c */

int take_tetrimino(tetrimino_t *tetri, FILE *fd, char *filepath, char *str);
tetrimino_t *init_struct_tetrimino(char *filepath);

/* stock_tetrimino.c */

char *take_name(char *str);
rlist *init_tetriminos(rlist *p_list, char *filepath);
int verif_name_tetrimino(char *name);
int add_tetriminos(struct dirent *sd, tetris_t *tet);
int stock_tetriminos(tetris_t *tet);


/* display.c */

void display_first_line(flags_t *fl, int a);
void display_map(flags_t *fl, g_tetris_t *g_tet);
void display_info_second(flags_t *fl, g_tetris_t *g_tet);
void display_info_first(flags_t *fl, g_tetris_t *g_tet);
void display_ncurses(flags_t *fl, g_tetris_t *g_tet);

/* line_full.c */

void go_down_line_full(tetris_t *tet);
void supress_line_full(tetris_t *tet, int y);
void verif_line_full(tetris_t *tet);

/* pause .c */

int pause_menu(tetris_t *tet);

/* add_tetri.c */

struct node *random_tetrimino(tetris_t *tet);
int add_tetri_map_first(tetris_t *tet);
int add_tetri_map_second(tetris_t *tet);
int check_stars_tetri(tetris_t *tet);

/* main.c */

char *int_to_str(int nb);
int count_length(char *str);
int main(int argc, char **argv);

/* time.c */

void wait_before_start(tetris_t *tet);
void clock_down(tetris_t *tet, clock_t start);

/* event.c */

int event(tetris_t *tet, clock_t start);

/* display_next.c */

void display_next_tetri(flags_t *fl, g_tetris_t *g_tet);
void display_next_map(flags_t *fl, g_tetris_t *g_tet);

/* help.c */

void help(int argc, char **argv);

/* init_map.c */

char *init_str_map(flags_t *fl);
char **init_map(flags_t *fl);

/* terminal_too_small.c */

void terminal_too_small(tetris_t *tet);

/* down.c */

void transfert_tetri(tetris_t *tet);
int verif_go_down(tetris_t *tet);
void go_down(tetris_t *tet);

/* highscore.c */

int write_highscore(tetris_t *tet);
int read_highscore(tetris_t *tet);

/* right.c */

int verif_go_right(tetris_t *tet);
void go_right(tetris_t *tet);

/* left.c */

int verif_go_left(tetris_t *tet);
void go_left(tetris_t *tet);

/* game.c */

int start_game(tetris_t *tet);
void end_game(tetris_t *tet);
void space_on_next(tetris_t *tet);
int check_tetri_low(tetris_t *tet);
int game(tetris_t *tet);


#endif /* !INC_ */

#endif /* !TETRIS_H_ */