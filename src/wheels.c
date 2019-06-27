/*
** EPITECH PROJECT, 2019
** Need4Stek
** File description:
** Wheels
*/
#include "n4s.h"
#include <stdlib.h>

int set_car_speed(float middle)
{
    int ret;

    if (middle >= 2000)
        ret = execute_cmd("car_forward:1\n");
    else if (middle >= 1500)
        ret = execute_cmd("car_forward:0.8\n");
    else if (middle >= 1000)
        ret = execute_cmd("car_forward:0.6\n");
    else if (middle >= 600)
        ret = execute_cmd("car_forward:0.4\n");
    else if (middle >= 400)
        ret = execute_cmd("car_forward:0.2\n");
    else ret = execute_cmd("car_forward:0.1\n");
    return (ret);
}

int	right_or_left(float moy, char *angle)
{
    my_putstr(1, "wheels_dir:");
    if (moy < 0.0)
        my_putstr(1, "-");
    my_putstr(1, angle);
    angle = get_next_line(0);
    if (is_end(angle) == 0)
        return (1);
    return (0);
}

int change_wheels(data_t *data)
{
    int ret;

    if (data->middle >= 1500)
        ret = right_or_left(data->left - data->right, "0.005\n");
    else if (data->middle >= 1000)
        ret = right_or_left(data->left - data->right, "0.05\n");
    else if (data->middle >= 600)
        ret = right_or_left(data->left - data->right, "0.1\n");
    else if (data->middle >= 400)
        ret = right_or_left(data->left - data->right, "0.2\n");
    else if (data->middle >= 200)
        ret = right_or_left(data->left - data->right, "0.3\n");
    else ret = right_or_left(data->left - data->right, "0.5\n");
    return (ret);
}