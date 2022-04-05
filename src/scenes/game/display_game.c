/*
** EPITECH PROJECT, 2020
** display the game
** File description:
** dislpay the game scnene assets
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void select_dialog(sfRenderWindow *window, all_t *all)
{
    if (all->combat->stat->level == 1)
        sfRenderWindow_drawSprite(window, all->game->dialog[0]->sprite, NULL);
    if (all->combat->stat->level == 2)
        sfRenderWindow_drawSprite(window, all->game->dialog[1]->sprite, NULL);
    if (all->combat->stat->level == 3)
        sfRenderWindow_drawSprite(window, all->game->dialog[2]->sprite, NULL);
}

void choose_color_anim(all_t *all)
{
    static int j = 0;

    if (j == 0) {
        if (all->select->i == 1)
            all->game->value = 0;
        if (all->select->i == 2)
            all->game->value = 288;
        if (all->select->i == 3)
            all->game->value = 144;
        if (all->select->i == 4)
            all->game->value = 432;
        j = 1;
    }
}

void select_color_game(all_t *all, int a)
{
    sfIntRect offset1 = {0, a, 48, 48};
    sfIntRect offset2 = {288, a, 48, 48};
    sfIntRect offset3 = {144, a, 48, 48};
    sfIntRect offset4 = {432, a, 48, 48};

    if (all->select->i < 1)
        sfSprite_setTextureRect(all->game->objects[1]->sprite, offset1);
    if (all->select->i == 1)
        sfSprite_setTextureRect(all->game->objects[1]->sprite, offset1);
    if (all->select->i == 2)
        sfSprite_setTextureRect(all->game->objects[1]->sprite, offset2);
    if (all->select->i == 3)
        sfSprite_setTextureRect(all->game->objects[1]->sprite, offset3);
    if (all->select->i == 4)
        sfSprite_setTextureRect(all->game->objects[1]->sprite, offset4);
}

void champ_game(all_t *all)
{
    static int a = 0;

    if (all->select->k == 0)
        a = 0;
    if (all->select->k == 1)
        a = 192;
    if (all->game->character_move != 48)
        select_color_game(all, a);
}

void display_game_sprites(sfRenderWindow *window, all_t *all)
{
    sfSprite_setPosition(all->game->objects[1]->sprite,
        all->game->objects[1]->position);
    champ_game(all);
    sfRenderWindow_drawSprite(window, all->game->objects[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, all->game->objects[1]->sprite, NULL);
    if (all->game->diag_value == 1)
        select_dialog(window, all);
    animation(all);
    draw_particles(window, all);
    sfRenderWindow_drawSprite(window, all->game->objects[2]->sprite, NULL);
}