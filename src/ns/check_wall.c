/*
** EPITECH PROJECT, 2023
** n4s [WSL : Ubuntu]
** File description:
** check_wall
*/

#include "../../include/n4s.h"

int dist_ultra(error_lidar_t *error_lidar, int left, int right, int front)
{
    if (!error_lidar)
        return ERROR;
    if (left > right && front < 450) {
        exec("WHEELS_DIR:0.30", error_lidar);
        exec("CYCLE_WAIT:3", error_lidar);
        return SUCCESS;
    }
    if (right > left && front < 450) {
        exec("WHEELS_DIR:-0.30", error_lidar);
        exec("CYCLE_WAIT:3", error_lidar);
        return SUCCESS;
    }
    return ERROR;
}

int dist_short(error_lidar_t *error_lidar, int left, int right, int front)
{
    if (!error_lidar)
        return ERROR;
    if (left > right && front < 800 && front > 450) {
        exec("WHEELS_DIR:0.22", error_lidar);
        exec("CYCLE_WAIT:3", error_lidar);
        return SUCCESS;
    }
    if (right > left && front < 800 && front > 450) {
        exec("WHEELS_DIR:-0.22", error_lidar);
        exec("CYCLE_WAIT:3", error_lidar);
        return SUCCESS;
    }
    return dist_ultra(error_lidar, left, right, front);
}

int dist_middle(error_lidar_t *error_lidar, int left, int right, int front)
{
    if (!error_lidar)
        return ERROR;
    if (left > right + 100 && front > 800) {
        exec("WHEELS_DIR:0.07", error_lidar);
        return SUCCESS;
    }
    if (right > left + 100 && front > 800) {
        exec("WHEELS_DIR:-0.07", error_lidar);
        return SUCCESS;
    }
    return dist_short(error_lidar, left, right, front);
}

int dist_long(error_lidar_t *error_lidar, int left, int right, int front)
{
    if (!error_lidar)
        return ERROR;
    if (left > right + 500 && front < 2200 && front > 1500) {
        exec("WHEELS_DIR:0.05", error_lidar);
        return SUCCESS;
    }
    if (right > left + 500 && front < 2200 && front > 1500) {
        exec("WHEELS_DIR:-0.05", error_lidar);
        return SUCCESS;
    }
    return dist_middle(error_lidar, left, right, front);
}

int check_wall_direction(error_lidar_t *error_lidar,
int left, int right, int front)
{
    if (!error_lidar)
        return ERROR;
    if (right == 0) {
        exec("WHEELS_DIR:0.20", error_lidar);
        return SUCCESS;
    }
    if (left == 0) {
        exec("WHEELS_DIR:-0.20", error_lidar);
        return SUCCESS;
    }
    if (dist_long(error_lidar, left, right, front) == SUCCESS)
        return SUCCESS;
    exec("WHEELS_DIR:0.00", error_lidar);
    return SUCCESS;
}
