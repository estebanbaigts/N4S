/*
** EPITECH PROJECT, 2023
** n4s [WSL : Ubuntu]
** File description:
** my_str_to_word_array
*/

#include "../include/n4s.h"

static char **my_create_tab(int nb_line, int nb_char)
{
    char **tab = NULL;

    if (nb_line <= 1 || nb_char <= 0)
        return tab;
    tab = malloc(sizeof(char*) * nb_line);
    for (int i = 0; i < nb_line; i++) {
        tab[i] = malloc(sizeof(char) * nb_char + 1);
        tab[i][nb_char] = '\0';
    }
    return tab;
}

static char **fill_array(char **array, char const *str, char separator)
{
    int select_str = 0;
    int select_char = 0;

    if (!array || !str)
        return NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == separator) {
            array[select_str][select_char] = '\0';
            select_str++;
            select_char = 0;
        } else {
            array[select_str][select_char] = str[i];
            select_char++;
        }
    }
    return NULL;
}

static int nb_words(char const *str, char separator)
{
    int nb_words = 1;

    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator && str[i + 1] != '\0'
        && str[i + 1] != separator)
            nb_words++;
    }
    nb_words++;
    return nb_words;
}

static int nb_char_max(char const *str, char separator)
{
    int nb_char = 0;
    int nb_char_max = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        nb_char++;
        if (str[i] == separator)
            nb_char = 0;
        if (nb_char >= nb_char_max)
            nb_char_max = nb_char;
    }
    nb_char_max++;
    return nb_char_max;
}

char **my_str_to_word_array(char const *str, char separator, char **dist_wall)
{
    char **array = NULL;

    my_free(dist_wall);
    if (!str)
        return NULL;
    array =
    my_create_tab(nb_words(str, separator), nb_char_max(str, separator));
    if (!array)
        return NULL;
    fill_array(array, str, separator);
    return array;
}
