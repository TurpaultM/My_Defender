/*
** EPITECH PROJECT, 2021
** defender
** File description:
** menu
*/

#pragma once
#include "my.h"

typedef struct button_s {
    sfSprite *button_sprite;
    sfTexture *button_texture;
    sfVector2f pos;
    sfVector2f size;
} button_t;
void menu(global_t *glob);
button_t **init_button(button_t **button);
void analyse_events(global_t *glob, button_t **button);
void clic_button(global_t *glob, button_t **button);
