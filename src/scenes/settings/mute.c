/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void mute_gestion(all_t *all)
{
    if (all->settings->i == 1)
        all->settings->j = 1;
    if (all->settings->k == 1)
        all->settings->l = 1;
    if (all->settings->i == 2)
        all->settings->j = 2;
    if (all->settings->k == 2)
        all->settings->l = 2;
}