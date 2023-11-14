/*
** EPITECH PROJECT, 2023
** n4s
** File description:
** my_strcmp
*/

#include "../include/n4s.h"

int my_strcmp(char const *s1, char const *s2)
{
    int index = 0;

    if (!s1 || !s2)
        return 0;
    if (strlen(s1) != strlen(s2))
        return 0;
    while (s1[index] != '\0' && s2[index] != '\0') {
        if (s1[index] != s2[index])
            return 0;
        index++;
    }
    return 1;
}
