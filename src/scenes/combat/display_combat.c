/*
** EPITECH PROJECT, 2020
** display_combat.c
** File description:
** display of the combat sprites
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void update_assets(all_t *all)
{
    char *tmp = my_itoa(all->combat->enemy_stats->life_enemy);

    sfText_setString(all->combat->enemy_stats->text_enemy_life, tmp);
    tmp = my_itoa(all->combat->stat->life);
    sfText_setString(all->combat->stat->text_life, tmp);
    free(tmp);
}

void display_mage_text(sfRenderWindow *window, all_t *all)
{
    sfText_setColor(all->combat->mage_2, sfGreen);
    sfText_setColor(all->combat->mage_3, sfGreen);
    if (all->combat->stat->level < 2 || all->combat->cooldown_buff > 0)
        sfText_setColor(all->combat->mage_2, sfRed);
    if (all->combat->stat->level < 4 || all->combat->cooldown_ult > 0)
        sfText_setColor(all->combat->mage_3, sfRed);

    sfRenderWindow_drawText(window, all->combat->mage_1, NULL);
    sfRenderWindow_drawText(window, all->combat->mage_2, NULL);
    sfRenderWindow_drawText(window, all->combat->mage_3, NULL);
}

void display_warrior_text(sfRenderWindow *window, all_t *all)
{
    sfText_setColor(all->combat->warrior_2, sfGreen);
    sfText_setColor(all->combat->warrior_3, sfGreen);
    if (all->combat->stat->level < 2 || all->combat->cooldown_buff > 0)
        sfText_setColor(all->combat->warrior_2, sfRed);
    if (all->combat->stat->level < 4 || all->combat->cooldown_ult > 0)
        sfText_setColor(all->combat->warrior_3, sfRed);
    sfRenderWindow_drawText(window, all->combat->warrior_1, NULL);
    sfRenderWindow_drawText(window, all->combat->warrior_2, NULL);
    sfRenderWindow_drawText(window, all->combat->warrior_3, NULL);
}

void display_combat_sprites(sfRenderWindow *window, all_t *all)
{
    sfRenderWindow_drawSprite(window, all->combat->objects[0]->sprite, NULL);
    champ_combat(all);
    sfRenderWindow_drawSprite(window, all->combat->objects[1]->sprite, NULL);
    sfRenderWindow_drawSprite(window,
            all->combat->enemy[all->combat->stat->level - 1]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->combat->objects[2]->sprite, NULL);
}

void display_combat(sfRenderWindow *window, all_t *all)
{
    update_assets(all);
    display_combat_sprites(window, all);
    if (all->select->k == 0)
        display_warrior_text(window, all);
    if (all->select->k == 1)
        display_mage_text(window, all);

    sfRenderWindow_drawText(window, all->combat->stat->text_life, NULL);
    sfRenderWindow_drawText(window,
                            all->combat->enemy_stats->text_enemy_life, NULL);
}