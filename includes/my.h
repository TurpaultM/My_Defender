/*
** EPITECH PROJECT, 2021
** library for my
** File description:
** add file my
*/

#ifndef _MY_
    #define _MY_
    #include <time.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <signal.h>
    #include "printf.h"
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
typedef struct win_lose {
    sfSprite *image;
    sfTexture *end_back;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f pos_text;
} win_lose;
typedef struct rdd_s {
    sfSprite *Jigglypuff_s;
    sfTexture *Jigglypuff_t;
    sfVector2f movement;
    sfVector2f size;
    sfTime time;
    sfClock *up;
    sfClock *down;
    sfClock *rigth;
    sfClock *left;
    sfClock *left_anim;
    sfClock *rigth_anim;
    sfClock *up_anim;
    sfClock *down_anim;
    float sec;
    float sec_anim;
    sfIntRect anim;
} rdd_t;
typedef struct coins_s {
    int nb_of_coins;
    sfFont *font;
    char *string;
    sfVector2f position;
    sfText *text;
    sfSprite *sprite;
    sfTexture *texture;
} coins_t;
typedef struct music_s {
    sfMusic *music;
    float pow;
    sfIntRect volume;
    sfIntRect sound;
    float pow_sound;
} music_t;
typedef struct global_s {
    sfRenderWindow *window;
    sfEvent event;
    coins_t *coins;
    rdd_t *rdd;
    char *pokedex_access;
    music_t music;
    win_lose *success;
} global_t;
int my_len(int *);
char *inttochar(int nb);
void menu(global_t *glob);
int my_arrlen(char **arr);
char *my_strstr(char *str, char *to_find);
char *my_strdup(char *src);
char *my_revstr(char *str);
void menu_game(global_t *glob);
int my_strlen(char const *str);
int my_strcmp(char *s1, char *s2);
char **my_strtok(char *str, char lim);
void option(global_t *glob, int scene);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
char **my_str_word_array(char *str, char lim);
char *concat_n_string(char *dest, char *src, int n);
int my_strncmp(char *s1, char *s2, int n);
#endif
