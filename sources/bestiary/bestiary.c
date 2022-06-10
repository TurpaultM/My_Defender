/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu game
*/

#include "game_defender.h"

static const int nb_pokemon = 16;

void destroy_poke(poke_t **pok)
{
    for (int i = 0; i < nb_pokemon; i++) {
        sfTexture_destroy(pok[i]->texture);
        sfSprite_destroy(pok[i]->sprite);
    }
}

static void button_back(global_t *glob, poke_t **pok)
{
    destroy_poke(pok);
    menu_game(glob);
}

static void analyse_events(global_t *glob, poke_t **pok)
{
    sfRenderWindow_display(glob->window);
    while (sfRenderWindow_pollEvent(glob->window, &glob->event)) {
        if (glob->event.type == sfEvtClosed) {
            destroy_poke(pok);
            sfRenderWindow_close(glob->window);
        }
        if (glob->event.type == sfEvtMouseButtonPressed
        && glob->event.mouseButton.button == sfMouseLeft &&
        glob->event.mouseButton.x >= 1635
        && glob->event.mouseButton.x <= 1885
        && glob->event.mouseButton.y >= 960
        && glob->event.mouseButton.y <= 1005) {
            button_back(glob, pok);
        }
        if (glob->event.type == sfEvtMouseWheelScrolled) {
            scroll_down(glob, pok);
            scroll_up(glob, pok);
        }
    }
}

void draw(global_t *glob, poke_t **pok, sfSprite *back)
{
    sfRenderWindow_clear(glob->window, sfWhite);
    sfRenderWindow_drawSprite(glob->window, back, sfFalse);
    for (int i = 0; i < nb_pokemon; i++) {
        sfRenderWindow_drawSprite(glob->window, pok[i]->sprite, sfFalse);
    }
}

void pokedex(global_t *glob)
{
    sfSprite *back = sfSprite_create();
    sfTexture *fond =
    sfTexture_createFromFile("image/pokedex/pokeback.jpg", NULL);
    sfVector2f size = {1, 0.96};
    poke_t **pok = malloc(sizeof(poke_t *) * nb_pokemon);

    sfSprite_setScale(back, size);
    sfSprite_setTexture(back, fond, sfFalse);
    init_pok(pok, glob);
    while (sfRenderWindow_isOpen(glob->window)) {
        draw(glob, pok, back);
        analyse_events(glob, pok);
    }
}
