/*
** EPITECH PROJECT, 2017
** str
** File description:
** str
*/

char *my_strstr(char *str, char *to_find)
{
    if (str[0] == '\0')
        return (0);
    for (int x = 0; to_find[x] != '\0'; x++) {
        if (to_find[x] != str[x]) {
            return (my_strstr(str + 1, to_find));
        }
    }
    return (str);
}
