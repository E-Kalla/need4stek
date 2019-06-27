/*
** EPITECH PROJECT, 2019
** Need4Stek
** File description:
** String to Wordtab
*/
#include "n4s.h"
#include <stdio.h>
#include <stdlib.h>

int wd_lenght(char *str, int i)
{
    int counter = 0;

    for (i; str[i] != '\0' && str[i] != ':'; i += 1, counter += 1);
    return (counter);
}

int wd_counter(char *str)
{
    int counter = 1;

    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == ':')
            counter += 1;
    return (counter);
}

char **str_to_tab(char *str)
{
    char **tab = malloc(sizeof(char *) * (wd_counter(str) + 1));
    int x;
    int y = 0;

    for (int i = 0; str[i] != '\0';) {
        x = 0;
        if (!(tab[y] = malloc(sizeof(char) * (wd_lenght(str, i) + 1))))
            return (NULL);
        while (str[i] != '\0' && str[i] != ':')
            tab[y][x++] = str[i++];
        while (str[i] == ':')
            i++;
        tab[y][x] = '\0';
        y++;
    }
    tab[y] = '\0';
    return (tab);
}