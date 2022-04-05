/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int f = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb *-1;
    }
    if (nb / 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}
