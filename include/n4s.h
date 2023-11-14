/*
** EPITECH PROJECT, 2023
** n4s [WSL : Ubuntu]
** File description:
** n4s
*/

#ifndef N4S_H_
    #define N4S_H_
    #define ERROR 84
    #define SUCCESS 0
    #include "struct.h"
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

int need_steak(void);
int my_free(char **array);
int my_strcmp(char const *s1, char const *s2);
int start_car(error_lidar_t *error_lidar);
int stop_simulation(error_lidar_t *error_lidar);
void exec(char *cmd, error_lidar_t *error_lidar);
int turn_ia(error_lidar_t *error_lidar, char **wall);
int move_car(error_lidar_t *error_lidar, float speed);
static int get_distance(int one, int two, char **wall);
static int speed(error_lidar_t *error_lidar, int front);
int choose_speed(error_lidar_t *error_lidar, int front);
static int choose_wheels_dir(char **wall, error_lidar_t *error_lidar);
int dist_ultra(error_lidar_t *error_lidar, int left, int right, int front);
int dist_short(error_lidar_t *error_lidar, int left, int right, int front);
int dist_middle(error_lidar_t *error_lidar, int left, int right, int front);
int dist_long(error_lidar_t *error_lidar, int left, int right, int front);
int check_wall_direction(error_lidar_t *error_lidar,
int left, int right, int front);
int detect_wall(error_lidar_t *error_lidar);
char **my_str_to_word_array(char const *str, char separator, char **dist_wall);
static int nb_char_max(char const *str, char separator);
static int nb_words(char const *str, char separator);
static char **fill_array(char **array, char const *str, char separator);
static char **my_create_tab(int nb_line, int nb_char);
#endif /* !N4S_H_ */
