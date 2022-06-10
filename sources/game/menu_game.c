/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu game
*/

#include "game_defender.h"
#include "game.h"

void destroy_all(rdd_t *jigg, button_t **butt)
{
    for (int i = 0; i != 4; i++) {
        sfTexture_destroy(butt[i]->button_texture);
        sfSprite_destroy(butt[i]->button_sprite);
    }
    sfSprite_destroy(jigg->Jigglypuff_s);
    sfTexture_destroy(jigg->Jigglypuff_t);
    sfClock_destroy(jigg->left);
    sfClock_destroy(jigg->left_anim);
    sfClock_destroy(jigg->down);
    sfClock_destroy(jigg->down_anim);
    sfClock_destroy(jigg->rigth);
    sfClock_destroy(jigg->rigth_anim);
    sfClock_destroy(jigg->up);
    sfClock_destroy(jigg->up_anim);
}

void button_clic(global_t *glob)
{
    if (glob->event.mouseButton.x > 1755 && glob->event.mouseButton.y > 625
    && glob->event.mouseButton.x < 1875 && glob->event.mouseButton.y < 685) {
        how_to_play(glob);
    }
    if (glob->event.mouseButton.x > 1755 && glob->event.mouseButton.y > 725
    && glob->event.mouseButton.x < 1875 && glob->event.mouseButton.y < 785) {
        pokedex(glob);
    }
    if (glob->event.mouseButton.x > 1755 && glob->event.mouseButton.y > 825
    && glob->event.mouseButton.x < 1875 && glob->event.mouseButton.y < 885) {
        option(glob, 2);
    }
    if (glob->event.mouseButton.x > 1755 && glob->event.mouseButton.y > 925
    && glob->event.mouseButton.x < 1875 && glob->event.mouseButton.y < 985) {
        menu(glob);
    }
}

static void analyse_events(global_t *glob, rdd_t *jigglypuff, button_t **butt)
{
    sfRenderWindow_display(glob->window);
    while (sfRenderWindow_pollEvent(glob->window, &glob->event)) {
        if (glob->event.type == sfEvtClosed) {
            sfRenderWindow_close(glob->window);
            destroy_all(jigglypuff, butt);
        }
        if (glob->event.type == sfEvtKeyPressed
        && glob->event.key.code == sfKeyEnter) {
            jiggly_collide(glob, jigglypuff);
        }
        if (glob->event.type == sfEvtMouseButtonPressed) {
            button_clic(glob);
        }
    }
    jigglypuff_movement(jigglypuff);
}

void draw_all(global_t *glob, rdd_t *jigg,
button_t **butt, sfSprite *back)
{
    sfSprite_setTextureRect(jigg->Jigglypuff_s, jigg->anim);
    sfRenderWindow_drawSprite(glob->window, back, sfFalse);
    sfRenderWindow_drawSprite(glob->window, jigg->Jigglypuff_s, sfFalse);
    sfRenderWindow_drawSprite(glob->window, butt[0]->button_sprite, sfFalse);
    sfRenderWindow_drawSprite(glob->window, butt[1]->button_sprite, sfFalse);
    sfRenderWindow_drawSprite(glob->window, butt[2]->button_sprite, sfFalse);
    sfRenderWindow_drawSprite(glob->window, butt[3]->button_sprite, sfFalse);
}

void menu_game(global_t *glob)
{
    sfSprite *back = sfSprite_create();
    sfTexture *fond =
    sfTexture_createFromFile("image/map/MAP_POKEMON.png", NULL);
    sfVector2f size = {2.35, 2.35};
    button_t **butt = malloc(sizeof(button_t *) * 4);

    if (glob->coins->nb_of_coins < 250)
        glob->coins->nb_of_coins = 250;
    init_butt(butt);
    sfSprite_setPosition(glob->rdd->Jigglypuff_s, glob->rdd->movement);
    sfSprite_setScale(back, size);
    sfSprite_setScale(glob->rdd->Jigglypuff_s, glob->rdd->size);
    sfSprite_setTexture(back, fond, sfFalse);
    while (sfRenderWindow_isOpen(glob->window)) {
        draw_all(glob, glob->rdd, butt, back);
        analyse_events(glob, glob->rdd, butt);
        sfRenderWindow_clear(glob->window, sfWhite);
        display_coins(glob->window, glob->coins);
    }
}
