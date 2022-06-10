/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** initialisation
*/

#include "game_defender.h"

void init_end_condition(global_t *glob)
{
    glob->success = malloc(sizeof(win_lose));
    glob->success->image = sfSprite_create();
    glob->success->end_back =
    sfTexture_createFromFile("image/map/win_lose.jpg", NULL);
    glob->success->text = sfText_create();
    glob->success->font = sfFont_createFromFile("Police/pokemon.ttf");
    glob->success->pos.x = 555;
    glob->success->pos.y = 310;
    glob->success->pos_text.x = 655;
    glob->success->pos_text.y = 370;
    sfText_setFont(glob->success->text, glob->success->font);
    sfSprite_setTexture(glob->success->image,
    glob->success->end_back, sfFalse);
}
