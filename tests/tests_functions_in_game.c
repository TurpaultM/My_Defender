/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** tests_functions_in_game
*/

#include "../includes/game_defender.h"
#include <criterion/criterion.h>

Test(kabuto_attack, attacks)
{
    defenders_t *defender = malloc(sizeof(defenders_t));
    enemies_t *enemy = malloc(sizeof(enemies_t));
    defender->sprite = sfSprite_create();
    sfSprite_setPosition(defender->sprite, (sfVector2f){500, 500});
    defender->initial_pos = (sfVector2f){530, 530};
    defender->is_restarting = false;
    defender->damages = 20;
    enemy->hp = 100;
    kabuto_attack(defender, (sfVector2f){500, 500}, (sfVector2f){500, 500},
    enemy);
    sfVector2f position = sfSprite_getPosition(defender->sprite);
    cr_assert_eq(enemy->hp, 80);
    cr_assert_eq(530, position.x);
    cr_assert_eq(530, position.y);
}

Test(umbreon_attack, attacks)
{
    defenders_t *defender = malloc(sizeof(defenders_t));
    enemies_t *enemy = malloc(sizeof(enemies_t));
    sfVector2f pos = {275, 275};
    defender->attack_sprite = sfSprite_create();
    sfSprite_setPosition(defender->attack_sprite, (sfVector2f){310, 310});
    enemy->speed = 5;
    enemy->hp = 500;
    defender->damages = 100;
    defender->initial_attack_pos = (sfVector2f){270, 270};
    defender->is_restarting = false;
    umbreon_attack(defender, pos, enemy);
    sfVector2f new_pos = sfSprite_getPosition(defender->attack_sprite);
    cr_assert_eq(new_pos.x, 270);
    cr_assert_eq(new_pos.y, 270);
    cr_assert_eq(enemy->hp, 400);
}

Test(calculate_to_rotate, attacks)
{
    int result = calculate_to_rotate((float)-129, (float)-17);
    cr_assert_eq(187,  result);
    result = calculate_to_rotate((float)-1, (float)191);
    cr_assert_eq(110,  result);
    result = calculate_to_rotate((float)71, (float)-71);
    cr_assert_eq(-65,  result);
    result = calculate_to_rotate((float)39, (float)233);
    cr_assert_eq(80,  result);
}

Test(deg, attacks)
{
    int result = deg(0.6806784084);
    cr_assert_eq(39, result);
}

Test(put_in_str, display)
{
    char *string = malloc(sizeof(char) * 5);
    string = put_in_str(523, string);
    cr_assert_str_eq(string, "523");
}

Test(all_pokemons_are_destroyed_false, end_of_the_game)
{
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    char *string;
    pokemons->enemies = malloc(sizeof(enemies_t *) * 53);
    for (int i = 0; i < 53; i++)
        pokemons->enemies[i] = malloc(sizeof(enemies_t));
    pokemons->nb_total = 53;
    pokemons->nb_of_pokemons = 42;
    for (int i = 0; i < 53; i++) {
        pokemons->enemies[i]->is_on_map = false;
    }
    pokemons->enemies[26]->is_on_map = true;
    if (all_pokemons_are_destroyed(pokemons) == true)
        string = "true";
    else
        string = "false";
    cr_assert_str_eq(string, "false");
}

Test(all_pokemons_are_destroyed_true, end_of_the_game)
{
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    char *string;
    pokemons->enemies = malloc(sizeof(enemies_t *) * 53);
    for (int i = 0; i < 53; i++)
        pokemons->enemies[i] = malloc(sizeof(enemies_t));
    pokemons->nb_total = 53;
    pokemons->nb_of_pokemons = 42;
    for (int i = 0; i < 53; i++) {
        pokemons->enemies[i]->is_on_map = false;
    }
    if (all_pokemons_are_destroyed(pokemons) == true)
        string = "true";
    else
        string = "false";
    cr_assert_str_eq(string, "false");
}

Test(find_which_one_majikarp, evolutions)
{
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    pokemons->placed_defenders = malloc(sizeof(defenders_t *) * 16);
    for (int i = 0; i < 16; i++)
        pokemons->placed_defenders[i] = malloc(sizeof(defenders_t));
    pokemons->placed_defenders[0]->name = "majikarp";
    cr_assert_eq(2, find_which_one(pokemons, 0));
}

Test(find_which_one_numel, evolutions)
{
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    pokemons->placed_defenders = malloc(sizeof(defenders_t *) * 16);
    for (int i = 0; i < 16; i++)
        pokemons->placed_defenders[i] = malloc(sizeof(defenders_t));
    pokemons->placed_defenders[0]->name = "numel";
    cr_assert_eq(4, find_which_one(pokemons, 0));
}

Test(find_which_one_kabuto, evolutions)
{
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    pokemons->placed_defenders = malloc(sizeof(defenders_t *) * 16);
    for (int i = 0; i < 16; i++)
        pokemons->placed_defenders[i] = malloc(sizeof(defenders_t));
    pokemons->placed_defenders[0]->name = "kabuto";
    cr_assert_eq(6, find_which_one(pokemons, 0));
}

Test(is_an_evolved_true, initialize_pokemons)
{
    int result;
    if (is_an_evolved(2) == true)
        result = 0;
    else
        result = 1;
    cr_assert_eq(result, 0);
}

Test(is_an_evolved_false, initialize_pokemons)
{
    int result;
    if (is_an_evolved(3) == true)
        result = 0;
    else
        result = 1;
    cr_assert_eq(result, 1);
}

Test(go_right, movements_functions)
{
    enemies_t **enemies = malloc(sizeof(enemies_t *) * 2);
    for (int i = 0; i < 2; i++)
        enemies[i] = malloc(sizeof(enemies_t));
    movements_t *movements = malloc(sizeof(movements_t));
    movements->travelled_distance = malloc(sizeof(int) * 2);
    enemies[0]->speed = 5;
    enemies[0]->sprite = sfSprite_create();
    sfSprite_setPosition(enemies[0]->sprite, (sfVector2f){60, 60});
    movements->travelled_distance[0] = 100;
    go_right(enemies, movements, 0);
    sfVector2f position = sfSprite_getPosition(enemies[0]->sprite);
    cr_assert_eq(position.x, 65);
    cr_assert_eq(position.y, 60);
    cr_assert_eq(movements->travelled_distance[0], 105);
}

Test(go_top, movements_functions)
{
    enemies_t **enemies = malloc(sizeof(enemies_t *) * 2);
    for (int i = 0; i < 2; i++)
        enemies[i] = malloc(sizeof(enemies_t));
    movements_t *movements = malloc(sizeof(movements_t));
    movements->travelled_distance = malloc(sizeof(int) * 2);
    enemies[0]->speed = 5;
    enemies[0]->sprite = sfSprite_create();
    sfSprite_setPosition(enemies[0]->sprite, (sfVector2f){60, 60});
    movements->travelled_distance[0] = 100;
    go_top(enemies, movements, 0);
    sfVector2f position = sfSprite_getPosition(enemies[0]->sprite);
    cr_assert_eq(position.x, 60);
    cr_assert_eq(position.y, 55);
    cr_assert_eq(movements->travelled_distance[0], 105);
}

Test(go_down, movements_functions)
{
    enemies_t **enemies = malloc(sizeof(enemies_t *) * 2);
    for (int i = 0; i < 2; i++)
        enemies[i] = malloc(sizeof(enemies_t));
    movements_t *movements = malloc(sizeof(movements_t));
    movements->travelled_distance = malloc(sizeof(int) * 2);
    enemies[0]->speed = 5;
    enemies[0]->sprite = sfSprite_create();
    sfSprite_setPosition(enemies[0]->sprite, (sfVector2f){60, 60});
    movements->travelled_distance[0] = 100;
    go_down(enemies, movements, 0);
    sfVector2f position = sfSprite_getPosition(enemies[0]->sprite);
    cr_assert_eq(position.x, 60);
    cr_assert_eq(position.y, 65);
    cr_assert_eq(movements->travelled_distance[0], 105);
}

Test(check_end_of_deplacement, movements)
{
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    pokemons->movements = malloc(sizeof(movements_t));
    pokemons->movements->travelled_distance = malloc(sizeof(int) * 15);
    pokemons->movements->movements = malloc(sizeof(int) * 15);
    pokemons->movements->pos_pattern = malloc(sizeof(int) * 15);
    for (int i = 0; i < 15; i++) {
        pokemons->movements->travelled_distance[i] = 50;
        pokemons->movements->movements[i] = 100;
        pokemons->movements->pos_pattern[i] = 0;
    }
    pokemons->movements->travelled_distance[0] = 110;
    pokemons->nb_of_pokemons = 15;
    char **patterns = define_patterns();
    check_end_of_deplacement(pokemons, patterns);
    cr_assert_eq(pokemons->movements->travelled_distance[0], 0);
    cr_assert_eq(pokemons->movements->travelled_distance[1], 50);
    cr_assert_eq(pokemons->movements->pos_pattern[0], 5);
    cr_assert_eq(pokemons->movements->pos_pattern[1], 0);
}

Test(is_occuped, place_defenders_in_square)
{
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    pokemons->placed_defenders = malloc(sizeof(defenders_t *) * 10);
    int result;
    pokemons->nb_of_defenders = 10;
    for (int i = 0; i < 10; i++) {
        pokemons->placed_defenders[i] = malloc(sizeof(defenders_t));
        pokemons->placed_defenders[i]->which_square = 0;
    }
    pokemons->placed_defenders[4]->which_square = 6;
    pokemons->placed_defenders[7]->which_square = 12;
    if (is_occuped(pokemons, 6) == true)
        result = 1;
    else
        result = 0;
    cr_assert_eq(result, 1);
}

Test(is_on_square_false, place_defenders_in_square)
{
    int result;
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    pokemons->defenders = malloc(sizeof(defenders_t *) * 10);
    pokemons->placed_defenders = malloc(sizeof(defenders_t *) * 10);
    for (int i = 0; i < 10; i++) {
        pokemons->defenders[i] = malloc(sizeof(defenders_t));
        pokemons->placed_defenders[i] = malloc(sizeof(defenders_t));
        pokemons->placed_defenders[i]->which_square = 0;
        pokemons->defenders[i]->position.x = 50;
        pokemons->defenders[i]->position.y = 50;
    }
    pokemons->nb_of_defenders = 10;
    if (is_on_square(pokemons, (sfVector2i){450, 450}, 7) == true)
        result = 0;
    else
        result = 1;
    cr_assert_eq(result, 1);
}

Test(is_on_square_true, place_defenders_in_square)
{
    int result;
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    pokemons->defenders = malloc(sizeof(defenders_t *) * 10);
    pokemons->placed_defenders = malloc(sizeof(defenders_t *) * 10);
    for (int i = 0; i < 10; i++) {
        pokemons->defenders[i] = malloc(sizeof(defenders_t));
        pokemons->placed_defenders[i] = malloc(sizeof(defenders_t));
        pokemons->placed_defenders[i]->which_square = 0;
        pokemons->defenders[i]->position.x = 50;
        pokemons->defenders[i]->position.y = 50;
    }
    pokemons->nb_of_defenders = 10;
    if (is_on_square(pokemons, (sfVector2i){60, 80}, 7) == true)
        result = 0;
    else
        result = 1;
    cr_assert_eq(result, 0);
}

Test(change_old_def, place_defenders)
{
    cr_assert_eq(change_old_def(0, 1), 1);
    cr_assert_eq(change_old_def(1, 0), 1);
}

Test(check_if_pokemon_is_shiny, shiny)
{
    int result = 0;
    pokemons_t *pokemons = malloc(sizeof(pokemons_t));
    pokemons->enemies = malloc(sizeof(enemies_t *) * 2);
    for (int i = 0; i < 2; i++) {
        pokemons->enemies[i] = malloc(sizeof(enemies_t));
        pokemons->enemies[i]->shiny = true;
        pokemons->enemies[i]->which_pokemon = 0;
        pokemons->enemies[i]->sprite = sfSprite_create();
    }
    sfColor color1 = sfSprite_getColor(pokemons->enemies[0]->sprite);
    check_if_pokemon_is_shiny(pokemons, 0);
    sfColor color2 = sfSprite_getColor(pokemons->enemies[0]->sprite);
    if (color1.r != color2.r || color1.g != color2.g || color1.b != color2.b) {
        result = 1;
    }
    cr_assert_eq(result, 1);
}