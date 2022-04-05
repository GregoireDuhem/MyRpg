/*
** EPITECH PROJECT, 2020
** free_all.c
** File description:
** free all the structs and malloc
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void free_menu(all_t *all)
{
    for (int i = 0; i < 6; i++)
        sfTexture_destroy(all->menu->objects[i]->texture);
    for (int i = 0; i < 6; i++)
        sfSprite_destroy(all->menu->objects[i]->sprite);

    sfMusic_destroy(all->menu->audio[0]->sound);
    sfMusic_destroy(all->menu->audio[1]->sound);
    free(all->menu);
}

void free_settings(all_t *all)
{
    for (int i = 0; i < 8; i++)
        sfTexture_destroy(all->settings->objects[i]->texture);
    for (int i = 0; i < 8; i++)
        sfSprite_destroy(all->settings->objects[i]->sprite);
    sfFont_destroy(all->settings->fontopt);
}

void free_combat_2(all_t *all)
{
    sfText_destroy(all->combat->stat->text_life);
    sfText_destroy(all->combat->enemy_stats->text_enemy_life);
    sfText_destroy(all->combat->warrior_3);
    sfText_destroy(all->combat->warrior_1);
    sfText_destroy(all->combat->warrior_2);
    sfText_destroy(all->combat->mage_3);
    sfText_destroy(all->combat->mage_2);
    sfText_destroy(all->combat->mage_1);
    free (all->combat->stat);
    free(all->combat->enemy_stats);
    free(all->combat);
}

void free_combat(all_t *all)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(all->combat->objects[i]->texture);
        sfSprite_destroy(all->combat->objects[i]->sprite);
    }
    for (int i = 0; i < 11; i++) {
        sfTexture_destroy(all->combat->enemy[i]->texture);
        sfSprite_destroy(all->combat->enemy[i]->sprite);
    }
    for (int i = 0; i < 2; i++)
        sfMusic_destroy(all->combat->audio[i]->sound);
    free_combat_2(all);
}

void free_all(all_t *all)
{
    free_menu(all);
    free_settings(all);
    free_combat(all);
    free_select(all);
    free_pause(all);
    free_game(all);
    free_inventory(all);
    free_help(all);
    free_death(all);
    free_victory(all);
    free(all);
}