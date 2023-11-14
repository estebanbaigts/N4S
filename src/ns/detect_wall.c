/*
** EPITECH PROJECT, 2023
** n4s [WSL : Ubuntu]
** File description:
** detect_wall
*/

#include "../../include/n4s.h"

int detect_wall(error_lidar_t *error_lidar)
{
    char **dist_wall = NULL;
    char **array_copy = NULL;

    if (!error_lidar->line)
        return ERROR;
    while (1) {
        exec("GET_INFO_LIDAR", error_lidar);
        dist_wall = NULL;
        dist_wall = my_str_to_word_array(error_lidar->line, ':', array_copy);
        if (turn_ia(error_lidar, dist_wall) == ERROR)
            return SUCCESS;
    }
    return SUCCESS;
}
