/*
** EPITECH PROJECT, 2020
** init_combat.c
** File description:
** function to init the combat struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void select_color_combat(all_t *all, int a)
{
    sfIntRect offset1 = {0, a, 48, 48};
    sfIntRect offset2 = {288, a, 48, 48};
    sfIntRect offset3 = {144, a, 48, 48};
    sfIntRect offset4 = {432, a, 48, 48};

    if (all->select->i < 1)
        sfSprite_setTextureRect(all->combat->objects[1]->sprite, offset1);
    if (all->select->i == 1)
        sfSprite_setTextureRect(all->combat->objects[1]->sprite, offset1);
    if (all->select->i == 2)
        sfSprite_setTextureRect(all->combat->objects[1]->sprite, offset2);
    if (all->select->i == 3)
        sfSprite_setTextureRect(all->combat->objects[1]->sprite, offset3);
    if (all->select->i == 4)
        sfSprite_setTextureRect(all->combat->objects[1]->sprite, offset4);
}

void champ_combat(all_t *all)
{
    static int a = 0;

    if (all->select->k == 0)
        a = 96;
    if (all->select->k == 1)
        a = 288;
    select_color_combat(all, a);
}

void set_scale(combat_t *combat)
{
    for (int i = 0; i < 10; i++)
        sfSprite_setScale(combat->enemy[i]->sprite, (sfVector2f){5, 5});
    sfSprite_setScale(combat->enemy[10]->sprite, (sfVector2f){7, 7});
    sfSprite_setScale(combat->objects[1]->sprite, (sfVector2f){5, 5});
}