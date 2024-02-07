/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function
*/
#include "my.h"

static int value_return(char s1, char s2)
{
    if (s1 == s2)
        return 0;
    if (s1 < s2)
        return -1;
    return 1;
}

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = 0;

    while (s1[len_s1] != '\0')
        len_s1++;
    for (int i = 0; i <= (len_s1 - 1); i++) {
        if (s2[i] == '\0' || s1[i] == '\0' || s1[i] != s2[i]) {
            return value_return(s1[i], s2[i]);
        }
    }
    return (0);
}
