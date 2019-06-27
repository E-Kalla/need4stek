/*
** EPITECH PROJECT, 2019
** Need4STek
** File description:
** 
*/

#ifndef N4S_H_
#define N4S_H_

typedef struct data_s {
    int track_finished;
    char **lidar;
    float middle;
    float left;
    float right;
} data_t;

/* PROTOTYPES */

// File 'main.c'
void car_loop(data_t *data);
data_t *init_data(char *lidar);
char *get_cleaned_lidar(char *lid);
int execute_cmd(char *cmd);

// File 'wheels.c'
int set_car_speed(float middle);
int change_wheels(data_t *data);
int	right_or_left(float moy, char *angle);

// File 'utils.c'
void my_putstr(int fd, char *string);
int my_strlen(char *string);
int is_end(char *infos);
int my_strcmp(char *str1, char *str2);

// File 'get_next_line.c'
char *get_next_line(int fd);

// File 'str_to_tab.c'
char **str_to_tab(char *str);

#endif /* !N4S_H_ */