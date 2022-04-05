/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** function for the inventory
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void champ_inventory(sfRenderWindow *window, all_t *all)
{
    static int a = 0;

    if (all->select->k == 0)
        a = 0;
    if (all->select->k == 1)
        a = 50;
    select_color(all, a);

    sfSprite_setPosition(all->select->objects[2]->sprite,
        (sfVector2f){900, 540});
    sfSprite_setScale(all->select->objects[2]->sprite, (sfVector2f){5, 5});
    sfRenderWindow_drawSprite(window, all->select->objects[2]->sprite, NULL);
}

void display_inventory_sprites(sfRenderWindow *window, all_t *all)
{
    sfSprite_setTextureRect(all->inventory->objects[3]->sprite,
            all->inventory->objects[3]->rect);
    sfRenderWindow_drawSprite(window,
            all->inventory->objects[3]->sprite, NULL);
    sfRenderWindow_drawSprite(window,
            all->inventory->objects[0]->sprite, NULL);
    champ_inventory(window, all);
    if (all->inventory->eat == 0 && all->combat->stat->level >= 2)
        sfRenderWindow_drawSprite(window, all->game->objects[3]->sprite, NULL);
    if (all->inventory->shield == 0 && all->combat->stat->level >= 3)
        sfRenderWindow_drawSprite(window, all->game->objects[5]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->inventory->objects[2]->sprite, NULL);
    sfRenderWindow_drawText(window, all->inventory->pt_health, NULL);
    sfRenderWindow_drawText(window, all->inventory->pt_att, NULL);
    sfRenderWindow_drawText(window, all->inventory->pt_def, NULL);
    sfRenderWindow_drawText(window, all->inventory->health, NULL);
    sfRenderWindow_drawText(window, all->inventory->att, NULL);
    sfRenderWindow_drawText(window, all->inventory->def, NULL);
    sfRenderWindow_drawText(window, all->inventory->lvl, NULL);
    sfRenderWindow_drawText(window, all->inventory->nb_lvl, NULL);
}

void set_text3(all_t *all)
{
    sfText_setString(all->inventory->health, "HEALTH :");
    sfText_setFont(all->inventory->health, all->settings->fontopt);
    sfText_setCharacterSize(all->inventory->health, 50);
    sfText_setColor(all->inventory->health, sfWhite);
    sfText_setPosition(all->inventory->health, (sfVector2f){1250, 415});
    sfText_setString(all->inventory->att, "ATTACK :");
    sfText_setFont(all->inventory->att, all->settings->fontopt);
    sfText_setCharacterSize(all->inventory->att, 50);
    sfText_setColor(all->inventory->att, sfWhite);
    sfText_setPosition(all->inventory->att, (sfVector2f){1250, 515});
    sfText_setString(all->inventory->def, "DEFENSE :");
    sfText_setFont(all->inventory->def, all->settings->fontopt);
    sfText_setCharacterSize(all->inventory->def, 50);
    sfText_setColor(all->inventory->def, sfWhite);
    sfText_setPosition(all->inventory->def, (sfVector2f){1250, 615});
    sfText_setString(all->inventory->lvl, "LEVEL :");
    sfText_setFont(all->inventory->lvl, all->settings->fontopt);
    sfText_setCharacterSize(all->inventory->lvl, 50);
    sfText_setColor(all->inventory->lvl, sfWhite);
    sfText_setPosition(all->inventory->lvl, (sfVector2f){1250, 200});
}

void set_text2(all_t *all)
{
    all->inventory->str = my_itoa(all->combat->stat->life);
    sfText_setString(all->inventory->pt_health, all->inventory->str);
    sfText_setFont(all->inventory->pt_health, all->settings->fontopt);
    sfText_setCharacterSize(all->inventory->pt_health, 50);
    sfText_setColor(all->inventory->pt_health, sfWhite);
    sfText_setPosition(all->inventory->pt_health, (sfVector2f){1650, 415});
    all->inventory->str2 = my_itoa(all->combat->stat->attack);
    sfText_setString(all->inventory->pt_att, all->inventory->str2);
    sfText_setFont(all->inventory->pt_att, all->settings->fontopt);
    sfText_setCharacterSize(all->inventory->pt_att, 50);
    sfText_setColor(all->inventory->pt_att, sfWhite);
    sfText_setPosition(all->inventory->pt_att, (sfVector2f){1650, 515});
    all->inventory->str2 = my_itoa(all->combat->stat->defense);
    sfText_setString(all->inventory->pt_def, all->inventory->str2);
    sfText_setFont(all->inventory->pt_def, all->settings->fontopt);
    sfText_setCharacterSize(all->inventory->pt_def, 50);
    sfText_setColor(all->inventory->pt_def, sfWhite);
    sfText_setPosition(all->inventory->pt_def, (sfVector2f){1650, 615});
}

void set_text(all_t *all)
{
    all->inventory->str3 = my_itoa(all->combat->stat->level);
    sfText_setString(all->inventory->nb_lvl, all->inventory->str3);
    sfText_setFont(all->inventory->nb_lvl, all->settings->fontopt);
    sfText_setCharacterSize(all->inventory->nb_lvl, 50);
    sfText_setColor(all->inventory->nb_lvl, sfWhite);
    sfText_setPosition(all->inventory->nb_lvl, (sfVector2f){1650, 200});
    set_text2(all);
    set_text3(all);
}