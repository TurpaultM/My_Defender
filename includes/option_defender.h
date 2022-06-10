/*
** EPITECH PROJECT, 2021
** defender
** File description:
** option
*/

#pragma once
#include "my.h"
typedef struct button_s {
    sfSprite *button_sprite;
    sfTexture *button_texture;
    sfVector2f pos;
    sfVector2f size;
} button_t;
button_t **init_button_and_title(button_t **button);
void sound_bar(global_t *glob);
void volume_bar(global_t *glob);
