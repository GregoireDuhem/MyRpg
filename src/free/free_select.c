/*
** EPITECH PROJECT, 2020
** fre_select.
** File description:
** function to free select
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void free_select(all_t *all)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(all->select->objects[i]->texture);
        sfSprite_destroy(all->select->objects[i]->sprite);
    }
    sfMusic_destroy(all->select->audio[0]->sound);
    sfMusic_destroy(all->select->audio[1]->sound);
    free(all->select);
}

void free_pause(all_t *all)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(all->pause->pause_sprite[i]->texture);
        sfSprite_destroy(all->pause->pause_sprite[i]->sprite);
    }
    sfMusic_destroy(all->pause->audio[0]->sound);
    free(all->pause);
}