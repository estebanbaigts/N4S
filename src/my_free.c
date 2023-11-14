/*
** EPITECH PROJECT, 2023
** n4s [WSL : Ubuntu]
** File description:
** my_free
*/

#include "../include/n4s.h"

int my_free(char **array)
{
    if (!array)
        return ERROR;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    return SUCCESS;
}
