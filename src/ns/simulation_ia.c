/*
** EPITECH PROJECT, 2023
** n4s [WSL : Ubuntu]
** File description:
** simulation_ia
*/

#include "../../include/n4s.h"
#include <stdlib.h>

int stop_simulation(error_lidar_t *error_lidar)
{
    if (!error_lidar->line)
        return ERROR;
    fprintf(stdout, "STOP_SIMULATION\n");
    if (getline(&error_lidar->line, &error_lidar->size, stdin) == -1)
        return ERROR;
    fprintf(stderr, "%s\n", error_lidar->line);
    return SUCCESS;
}

int start_car(error_lidar_t *error_lidar)
{
    if (!error_lidar->line)
        return ERROR;
    fprintf(stdout, "START_SIMULATION\n");
    if (getline(&error_lidar->line, &error_lidar->size, stdin) == -1)
        return ERROR;
    fprintf(stderr, "%s\n", error_lidar->line);
    return SUCCESS;
}

int move_car(error_lidar_t *error_lidar, float speed)
{
    if (!error_lidar->line)
        return ERROR;
    fprintf(stdout, "%s:%f\n", "CAR_FORWARD", speed);
    if (getline(&error_lidar->line, &error_lidar->size, stdin) == -1)
        return ERROR;
    fprintf(stderr, "%s\n", error_lidar->line);
    return SUCCESS;
}

int need_steak(void)
{
    size_t size = 100;
    char *line = malloc(sizeof(char) * 100);
    error_lidar_t *error_lidar = malloc(sizeof(error_lidar_t));

    if (!line || !error_lidar)
        return ERROR;
    error_lidar->line = line;
    error_lidar->size = size;
    setvbuf(stdout, NULL, _IONBF, 0);
    if (start_car(error_lidar) == ERROR)
        return ERROR;
    if (move_car(error_lidar, 0.75) == ERROR)
        return ERROR;
    if (detect_wall(error_lidar) == ERROR)
        return ERROR;
    if (stop_simulation(error_lidar) == ERROR)
        return ERROR;
    return SUCCESS;
}

void exec(char *cmd, error_lidar_t *error_lidar)
{
    if (!cmd || !error_lidar)
        return;
    fprintf(stdout, "%s\n", cmd);
    if (getline(&error_lidar->line, &error_lidar->size, stdin) == -1)
        return;
    fprintf(stderr, "%s\n", error_lidar->line);
    return;
}
