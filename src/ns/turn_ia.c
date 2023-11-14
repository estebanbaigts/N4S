/*
** EPITECH PROJECT, 2023
** n4s [WSL : Ubuntu]
** File description:
** turn_ia
*/

#include "../../include/n4s.h"

static int get_distance(int one, int two, char **wall)
{
    int dist = 0;

    if (!wall)
        return 0;
    dist = atoi(wall[one]);
    dist += atoi(wall[two]);
    return dist;
}

static int choose_wheels_dir(char **wall, error_lidar_t *error_lidar)
{
    int dist_left = 0;
    int dist_right = 0;
    int dist_front = 0;
    char **check_end = NULL;

    if (!wall || !error_lidar)
        return ERROR;
    dist_left = get_distance(3, 10, wall);
    dist_right = get_distance(27, 34, wall);
    dist_front = atoi(wall[16]);
    check_wall_direction(error_lidar, dist_left, dist_right, dist_front);
    check_end = my_str_to_word_array(error_lidar->line, ':', check_end);
    if (check_end[3] != NULL && my_strcmp(check_end[3], "Lap Cleared\0") == 1)
        return ERROR;
    return SUCCESS;
}

int turn_ia(error_lidar_t *error_lidar, char **wall)
{
    if (!error_lidar || !wall)
        return ERROR;
    if (choose_speed(error_lidar, atoi(wall[16])) == ERROR)
        return ERROR;
    if (choose_wheels_dir(wall, error_lidar) == ERROR) {
        exec("CYCLE_WAIT:3\0", error_lidar);
        return ERROR;
    }
    if (wall[35] != NULL && my_strcmp(wall[35], "Track Cleared\0") == 1)
        return ERROR;
    if (wall[35] != NULL && my_strcmp(wall[35], "Lap Cleared\0") == 1)
        return ERROR;
    return SUCCESS;
}
