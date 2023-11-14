/*
** EPITECH PROJECT, 2023
** n4s [WSL : Ubuntu]
** File description:
** speed
*/

#include "../../include/n4s.h"

static int speed(error_lidar_t *error_lidar, int front)
{
    if (!error_lidar || !front)
        return ERROR;
    if (front < 1000) {
        exec("CAR_FORWARD:0.50", error_lidar);
        return SUCCESS;
    }
    if (front < 1800) {
        exec("CAR_FORWARD:0.60", error_lidar);
        return SUCCESS;
    }
    if (front < 2800) {
        exec("CAR_FORWARD:0.90", error_lidar);
        return SUCCESS;
    }
    exec("CAR_FORWARD:0.95", error_lidar);
    return SUCCESS;
}

int choose_speed(error_lidar_t *error_lidar, int front)
{
    char **end = NULL;

    if (!error_lidar || !front)
        return ERROR;
    if (front < 500) {
        exec("CAR_FORWARD:0.10", error_lidar);
        return SUCCESS;
    }
    if (front < 800) {
        exec("CAR_FORWARD:0.15", error_lidar);
        return SUCCESS;
    }
    speed(error_lidar, front);
    end = my_str_to_word_array(error_lidar->line, ':', end);
    if (end[3] != NULL && my_strcmp(end[3], "Lap Cleared\0") == 1)
        return ERROR;
    return SUCCESS;
}
