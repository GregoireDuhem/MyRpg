/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>

char my_putchar(char c)
{
    write(1, &c, 1);
}
