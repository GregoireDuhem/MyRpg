/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** car one by one in a string
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i])
    {
        my_putchar(str[i]);
        i++;
    }
}
