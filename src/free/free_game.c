/*
** EPITECH PROJECT, 2020
** free_game.c
** File description:
** free all the alloc
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void free_game(all_t *all)
{
    sfMusic_destroy(all->game->audio[0]->sound);
    sfMusic_destroy(all->game->audio[1]->sound);
    for (int i = 0; i < 6; ++i) {
        sfTexture_destroy(all->game->objects[i]->texture);
        sfSprite_destroy(all->game->objects[i]->sprite);
    }
    sfClock_destroy(all->game->anim);
    sfClock_destroy(all->game->clock);
    sfImage_destroy(all->game->hitbox);
    free(all->game);
}

void free_inventory(all_t *all)
{
    for (int i = 0; i < 4; ++i) {
        sfTexture_destroy(all->inventory->objects[i]->texture);
        sfSprite_destroy(all->inventory->objects[i]->sprite);
    }
    sfMusic_destroy(all->inventory->audio[0]->sound);
    sfText_destroy(all->inventory->health);
    sfText_destroy(all->inventory->def);
    sfText_destroy(all->inventory->att);
    sfText_destroy(all->inventory->pt_health);
    sfText_destroy(all->inventory->pt_def);
    sfText_destroy(all->inventory->pt_att);
    free(all->inventory);
}

void free_help(all_t *all)
{
    for (int i = 0; i < 4; ++i) {
        sfTexture_destroy(all->help->objects[i]->texture);
        sfSprite_destroy(all->help->objects[i]->sprite);
    }
    free(all->help);
}

void free_death(all_t *all)
{
    for (int i = 0; i < 2; ++i) {
        sfTexture_destroy(all->death->objects[i]->texture);
        sfSprite_destroy(all->death->objects[i]->sprite);
    }
    sfMusic_destroy(all->death->audio[0]->sound);
    sfMusic_destroy(all->death->audio[1]->sound);
    free(all->death);
}

void free_victory(all_t *all)
{
    for (int i = 0; i < 2; ++i) {
        sfTexture_destroy(all->victory->objects[i]->texture);
        sfSprite_destroy(all->victory->objects[i]->sprite);
    }
    sfMusic_destroy(all->victory->audio[0]->sound);
    sfMusic_destroy(all->victory->audio[1]->sound);
    free(all->victory);
}