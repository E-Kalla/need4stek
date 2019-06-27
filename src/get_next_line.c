/*
** EPITECH PROJECT, 2018
** Get Next Line
** File description:
** Get Next Line
*/
#include "n4s.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define READ_SIZE (1)

char *re_alloc_memory(char *str)
{
    char *temp;
    int i = 0;

    if ((temp = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
        return (NULL);
    while (str[i] != '\0') {
        temp[i] = str[i];
        i += 1;
    }
    temp[i + 1] = '\0';
    free(str);
    return (temp);
    free(temp);
}

char *get_next_line(int fd)
{
    int i = 0;
    int size = 0;
    char *str;
    static char buffer[READ_SIZE + 1];

    if ((str = malloc(sizeof(char) + 1)) == NULL)
        return (NULL);
    str[0] = '\0';
    while (size = read(fd, buffer, READ_SIZE) > 0) {
        if (buffer[0] == '\n')
            return (str);
        str = re_alloc_memory(str);
        str[i++] = buffer[0];
    }
    str[i] = '\0';
    if (size <= 0 && i == 0)
        return (NULL);
    else return (str);
    free(str);
}