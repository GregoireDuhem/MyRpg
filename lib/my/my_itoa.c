/*
** EPITECH PROJECT, 2020
** my_itoa.c
** File description:
** int to array
*/

#include <stdlib.h>
#include <stddef.h>

int my_int_len(int nb)
{
    int div;
    int count;

    div = 1;
    count = 1;
    while (nb / div >= 1)
    {
        div = div * 10;
        count = count + 1;
    }
    return (count);
}

char *my_itoa(int nb)
{
    int div;
    char *str;
    int i = my_int_len(nb);

    str = malloc(sizeof(char) * i);
    if (str == NULL)
        return (NULL);
    i = i - 1;
    div = 10;
    str[i] = '\0';
    while (i > 0)
    {
        str[i - 1] = (nb % div) + 48;
        nb = nb / 10;
        i = i - 1;
    }
    return (str);
}
