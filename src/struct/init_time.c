/*
** EPITECH PROJECT, 2020
** init_time.c
** File description:
** function to init a time_t struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

t_time *create_time_game(void)
{
    t_time *time = malloc(sizeof(t_time));
    time->clock = sfClock_create();
    time->second = 0;
    return time;
}