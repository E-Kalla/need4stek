/*
** EPITECH PROJECT, 2019
** Need4Stek
** File description:
** Main
*/
#include "n4s.h"
#include <stdlib.h>
#include <string.h>

char *get_cleaned_lidar(char *lid)
{
    int i = 0;
    int j = 0;
    char *tmp;

    if (!(tmp = malloc(sizeof(char) * my_strlen(lid))))
        return (NULL);
    while (i != 3)
        if (lid[j++] == ':')
            i++;
    i = 0;
    for (; lid[j] != '\0'; i++) {
        if (lid[j] >= '0' && lid[j] <= '9' || lid[j] == '.' || lid[j] == ':')
            tmp[i] = lid[j];
        j++;
    }
    tmp[i] = '\0';
    return (tmp);
}

data_t *init_data(char *lidar)
{
    data_t *data = malloc(sizeof(data_t));

    data->lidar = str_to_tab(lidar);
    data->middle = atof(data->lidar[15]);
    data->left = atof(data->lidar[0]);
    data->right = atof(data->lidar[31]);
    return (data);
}

void car_loop(data_t *data)
{
    char *lidar;

    while (data->track_finished != 1) {
        my_putstr(1, "get_info_lidar\n");
        lidar = get_next_line(0);
        is_end(lidar);
        lidar = get_cleaned_lidar(lidar);
        data = init_data(lidar);
        if (set_car_speed(data->middle) == 1) {
            data->track_finished = 1;
            break;
        }
        if (change_wheels(data) == 1) {
            data->track_finished = 1;
            break;
        }
    }
    free(lidar);
}

int execute_cmd(char *cmd)
{
    my_putstr(1, cmd);
    cmd = get_next_line(0);
    if (is_end(cmd) == 0)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    data_t data;

    data.track_finished = 0;
    execute_cmd("START_SIMULATION\n");
    car_loop(&data);
    execute_cmd("STOP_SIMULATION\n");
    return (0);
}