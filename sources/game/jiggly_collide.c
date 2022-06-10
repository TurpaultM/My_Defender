/*
** EPITECH PROJECT, 2022
** Boucard & Turpault
** File description:
** menu game
*/

#include "game_defender.h"


char *add_str(char *str, char *add)
{
    str = my_strcat(str, add);
    return (str);
}

void level_1_2(global_t *glob, rdd_t *jigg)
{
    if (jigg->movement.x >= 895 && jigg->movement.x <= 1065
    && jigg->movement.y >= 390 && jigg->movement.y <= 490) {
        sfSprite_setPosition(jigg->Jigglypuff_s, jigg->movement);
        glob->pokedex_access = add_str(glob->pokedex_access, "02");
        game(glob, "000  000     002       0220      22 0 00    00 2"
        " 2222 0002   00 0220 0  0 00 020 20 022 002 00  0 0  0 0 00 "
        "0 0   2   0 0 00000000   2 22     0 02  20 2  20 00 022 2022");
    }
    if (jigg->movement.x >= 1210 && jigg->movement.x <= 1355
    && jigg->movement.y >= 470 && jigg->movement.y <= 570) {
        sfSprite_setPosition(jigg->Jigglypuff_s, jigg->movement);
        glob->pokedex_access = add_str(glob->pokedex_access, "0123");
        game(glob, "00 22 0  0 202 00 0 00      0  00   01000 00    00 00"
        "0 000  001 010 0000 00  020  2 0 2200 00 00000 0 22  2 0 00 0 0 2 "
        "010 0 000 02 220 22  2202 2  22  3 22 32 2 32 3 3323 3 23 3332 33");
    }
}

void level_3_4(global_t *glob, rdd_t *jigg)
{
    if (jigg->movement.x >= 1305 && jigg->movement.x <= 1450
    && jigg->movement.y >= 820 && jigg->movement.y <= 920) {
        sfSprite_setPosition(jigg->Jigglypuff_s, jigg->movement);
        glob->pokedex_access = add_str(glob->pokedex_access, "2347");
        game(glob, "2 2 2   23 32 3 3 3 23    32 3  3 2 3  32   3  22 3 2"
        " 323 323 23 33234   24 3 22424    7   4473  2 375   32 743   7343 "
        "2 237 4  3 33 2 222   22  2 33 3  4 3 23 22  423 4  7 3 2 72  742");
    }
    if (jigg->movement.x >= 430 && jigg->movement.x <= 575
    && jigg->movement.y >= 370 && jigg->movement.y <= 470) {
        sfSprite_setPosition(jigg->Jigglypuff_s, jigg->movement);
        glob->pokedex_access = add_str(glob->pokedex_access, "3457");
        game(glob, "33 343 4 33334    3 3 4 4 4 5453   3 34  4 5  5 4 4 335"
        " 53 5 5 4  3 3333 43 44 4 44 3443433    33 73  3  3 77  7 37 37 3 "
        " 4 3  44  4 55  7  5 5 75  533  3   5  5 4  4 5 45   77 7 74 77");
    }
}

void level_5_6(global_t *glob, rdd_t *jigg)
{
    if (jigg->movement.x >= 700 && jigg->movement.x <= 845
    && jigg->movement.y >= 790 && jigg->movement.y <= 890) {
        sfSprite_setPosition(jigg->Jigglypuff_s, jigg->movement);
        glob->pokedex_access = add_str(glob->pokedex_access, "02378");
        game(glob, "00   0  0  0 2 3 0 0    2 32 323 3   2 2 3   0  00 0   "
        "7  3 2 3333  2 2 222   7 7 77    8       0 2  3     800   0  732  2"
        "   32 33 32  00 0 332 0  0 002   202 023 2 20 02 0220     02 2  3 7"
        "    7 77    32  7        88800       0200      88  8 8  0 8808 00");
    }
    if (jigg->movement.x >= 1485 && jigg->movement.x <= 1640
    && jigg->movement.y >= 160 && jigg->movement.y <= 260) {
        sfSprite_setPosition(jigg->Jigglypuff_s, jigg->movement);
        glob->pokedex_access = add_str(glob->pokedex_access, "45678");
        game(glob, "88  45      7 75 7588       54 44  5  5 4 45 4    54 4"
        "5 45 5 45  6 654 5 564 54 6 665 56 565  54  454 5 6   6 45 6   6"
        "     7 8 8  7   7  8 7 8 888 8   88865568878685      8688665678586"
        "  68884668 8668568 68565878575686685 85 85586 65     865 87   56 "
        "  7 65547 45  68  8 68 8  8 86 786 84   8486 468 6888 486 468 8");
    }
}

void jiggly_collide(global_t *glob, rdd_t *jigg)
{
    level_1_2(glob, jigg);
    level_3_4(glob, jigg);
    level_5_6(glob, jigg);
    if (jigg->movement.x >= 770 && jigg->movement.x <= 910
    && jigg->movement.y >= 110 && jigg->movement.y <= 210) {
        sfSprite_setPosition(jigg->Jigglypuff_s, jigg->movement);
        glob->pokedex_access = add_str(glob->pokedex_access, "012345678");
        game(glob, "7       00001110 10100111 01 1010 1011111  101011100 1001"
        " 0 0 110  23 30  10 01  02   8 80 00 0 808 08 080    45 35 02 550 32"
        "      1213 53004 04540041166 54    87 74512 5 4     888000  2245   7"
        "  80118  8 818181 881 1881 8 8 181118 181 1 8111881 18 8 1 1818 100 "
        "   02  35  56  6768 456 32   3 7 7 7  8 8 43 53   8 8 51 01    854  "
        "66 5   658  8 8687 8 85  4488860 0 5 045 8   40 4 06 0 646 648 6860 "
        " 77 0 8 88 8 8888 5 0       8811881811  180805486687045 0 54068888");
    }
}
