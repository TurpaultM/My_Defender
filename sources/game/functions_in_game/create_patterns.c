/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-alexandre.boucard
** File description:
** create_patterns
*/

#include "game.h"

char **attribuate_patterns(char **patterns)
{
    char **random_patterns = malloc(sizeof(char *) * 584);
    for (int i = 0; i < 584; i++) {
        int random = rand() % 4;
        random_patterns[i] = patterns[random];
    }
    return (random_patterns);
}

char **define_patterns(void)
{
    char **patterns = malloc(sizeof(char *) * 4);
    patterns[0] = "D140 B200 D390 H070 D590 B070 D390 H170 D400";
    patterns[1] = "D140 B200 D390 H310 D580 B310 D400 H170 D400";
    patterns[2] = "D140 H070 D380 H040 D570 B300 D390 H170 D400";
    patterns[3] = "D140 H090 D390 B220 D590 B070 D390 H170 D400";
    return (attribuate_patterns(patterns));
}
