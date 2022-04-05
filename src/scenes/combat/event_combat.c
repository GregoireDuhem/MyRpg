/*
** EPITECH PROJECT, 2020
** event_combat.c
** File description:
** function for the combat event
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void buff_reset(all_t *all)
{
    if (all->select->k == 0 && all->combat->cooldown_buff == 0)
        all->combat->stat->defense -= 10;
    if (all->select->k == 1 && all->combat->cooldown_buff == 0)
        all->combat->stat->attack -= 10;
}

int attack_1(all_t *all)
{
    int value = COMBAT;

    if (all->select->k == 0)
        value = attack_warrior_1(all);
    if (all->select->k == 1)
        value = attack_mage_1(all);
    return value;
}

int attack_2(all_t *all)
{
    int value = COMBAT;

    if (all->select->k == 0)
        value = attack_warrior_2(all);
    if (all->select->k == 1)
        value = attack_mage_2(all);
    return value;
}

int attack_3(all_t *all)
{
    int value = COMBAT;

    if (all->select->k == 0)
        value = attack_warrior_3(all);
    if (all->select->k == 1)
        value = attack_mage_3(all);
    return value;
}

int manage_click_combat(all_t *all, sfMouseButtonEvent event)
{
    int i = COMBAT;

    buff_reset(all);
    sfMusic_stop(all->menu->audio[1]->sound);
    sfMusic_play(all->menu->audio[1]->sound);
    if (event.y > 750 && event.y < 810
        && event.x > 1125 && event.x < 1600)
        i = attack_1(all);
    if (event.y > 830 && event.y < 895
        && event.x > 1125 && event.x < 1600)
        i = attack_2(all);
    if (event.y > 945 && event.y < 1010
        && event.x > 1125 && event.x < 1600)
        i = attack_3(all);

    if (all->combat->stat->life <= 0)
        i = DEATH;
    return i;
}