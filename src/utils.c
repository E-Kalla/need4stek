/*
** EPITECH PROJECT, 2019
** Need4Stek
** File description:
** Utils
*/
#include "n4s.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while ((str1[i] != '\0') && (str2[i] != '\0') && str1[i] == str2[i])
        i += 1;
    return (str1[i] - str2[i]);
}

int is_end(char *infos)
{
    int a = my_strlen(infos) - 1;
    int i = 0;
    char *end;

    if (!(end = malloc(sizeof(char) * my_strlen(infos))))
        return (1);
    for (a; infos[a] != ':' && infos[a] != 0; a--);
    a--;
    for (a; infos[a] != ':' && infos[a] != 0; a--);
    a++;
    for (i; infos[a] != ':'; a++, i++)
        end[i] = infos[a];
    end[i] = '\0';
    if (my_strcmp("Track Cleared\0", end) == 0) {
        free(end);
        execute_cmd("STOP_SIMULATION\n");
        return (0);
    }
    free(end);
    return (1);
}

int my_strlen(char *string)
{
    int i = 0;

    for (i; string[i] != '\0'; i++);
    return (i);
}

void my_putstr(int fd, char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
        write(fd, &string[i], 1);
}