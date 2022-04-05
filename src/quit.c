/*
** EPITECH PROJECT, 2020
** quit.c
** File description:
** function before the exit of the program
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int quit_main(sfRenderWindow *window, all_t *all)
{
    free_all(all);
    sfRenderWindow_close(window);
    return 0;
}