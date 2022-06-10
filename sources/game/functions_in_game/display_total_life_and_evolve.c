/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** display_total_life
*/

#include "game.h"

void display_total_life(sfRenderWindow *window, pokemons_t *pokemons,
sfFont *font)
{
    char *string = malloc(sizeof(char) * 2);
    if (pokemons->total_life <= 0)
        string = "0";
    else
        string = inttochar(pokemons->total_life);
    pokemons->text_total_life = sfText_create();
    sfText_setFont(pokemons->text_total_life, font);
    sfText_setString(pokemons->text_total_life, string);
    sfText_setColor(pokemons->text_total_life, sfRed);
    sfText_setPosition(pokemons->text_total_life, (sfVector2f){1820, 500});
    sfRenderWindow_drawText(window, pokemons->text_total_life, NULL);
    sfRenderWindow_drawSprite(window, pokemons->heart, NULL);
    if (pokemons->total_life > 0)
        free(string);
}

char *my_str_char_cat(char *str, char c)
{
    int i = my_strlen(str);
    str[i] = c;
    str[i + 1] = '\0';
    return (str);
}

char *put_in_str(int nb, char *str)
{
    if (nb >= 0 && nb <= 9) {
        my_str_char_cat(str, nb + 48);
        return (str);
    } else if (nb > 9) {
        put_in_str(nb / 10, str);
        put_in_str(nb % 10, str);
    }
    return (str);
}

void display_coins(sfRenderWindow *window, coins_t *coins)
{
    coins->string = inttochar(coins->nb_of_coins);
    sfText_setFont(coins->text, coins->font);
    sfText_setString(coins->text, coins->string);
    sfText_setPosition(coins->text, coins->position);
    sfText_setScale(coins->text, (sfVector2f){2, 2});
    sfText_setColor(coins->text, sfYellow);
    sfRenderWindow_drawText(window, coins->text, NULL);
    sfRenderWindow_drawSprite(window, coins->sprite, NULL);
}
