/*
** EPITECH PROJECT, 2020
** help_flag
** File description:
** print for the help flag
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void print_help(void)
{
    my_putstr("You can launch the game with './my_rpg' and ");
    my_putstr("go to help\n               for more information.\n\n");
    my_putstr("       You can escape the game with escape key.\n");
    my_putstr("      To move in the game you need to use 'zqsd'\n");

}

int help_flag(int ac, char **av)
{
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("\n/ *********************************************** \\");
        my_putstr("\n ");
        my_putstr("\n                Welcome to My_RPG");
        my_putstr("\n ");
        my_putstr("\n ");
        print_help();
        my_putstr("\n ");
        my_putstr("\n        Good luck & Have fun with our game !");
        my_putstr("\nCreated by Pierre Bittou, Thomas Ostrowski");
        my_putstr(", Grégoire Duhem\n\n");
        my_putstr("\\ ********************************************** /\n\n");
        return 1;
    }
    return 0;
}