/*
** EPITECH PROJECT, 2020
** button_animation.c
** File description:
** file for the button animation
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void button_animation_back(all_t *all, sfVector2f cursor_pos)
{
    sfIntRect offset1 = {0, 150, 150, 150};
    sfIntRect offset2 = {0, 0, 150, 150};

    if ((cursor_pos.x >= all->settings->objects[8]->position.x
        && cursor_pos.x <= all->settings->objects[8]->position.x + 150)
        && (cursor_pos.y >= all->settings->objects[8]->position.y
        && cursor_pos.y <= all->settings->objects[8]->position.y + 150))
        sfSprite_setTextureRect(all->settings->objects[8]->sprite, offset1);

    else
        sfSprite_setTextureRect(all->settings->objects[8]->sprite, offset2);
}

void button_animation_s(all_t *all, sfVector2f cursor_pos)
{
    button_animation_up_mu(all, cursor_pos);
    button_animation_up_sfx(all, cursor_pos);
    button_animation_down_mu(all, cursor_pos);
    button_animation_down_sfx(all, cursor_pos);
    button_animation_back(all, cursor_pos);
}

void manage_click_option_3(all_t *all)
{
    sfIntRect offset1 = {0, 100, 100, 100};
    sfIntRect offset2 = {0, 0, 100, 100};

    if (all->settings->i == 1)
        sfSprite_setTextureRect(all->settings->objects[6]->sprite, offset1);
    else if (all->settings->i == 2)
        sfSprite_setTextureRect(all->settings->objects[6]->sprite, offset2);
    if (all->settings->k == 1)
        sfSprite_setTextureRect(all->settings->objects[7]->sprite, offset1);
    else if (all->settings->k == 2)
        sfSprite_setTextureRect(all->settings->objects[7]->sprite, offset2);
}

void manage_click_option_2(all_t *all, sfMouseButtonEvent event)
{
    if (event.y > 410 && event.y < 490 && event.x > 1270 && event.x < 1350
        && all->settings->nb_sfx < 100)
        all->settings->nb_sfx += 5;
    else if (event.y > 510 && event.y < 590 && event.x > 1270 && event.x < 1350
        && all->settings->nb_mus < 100)
        all->settings->nb_mus += 5;
    if (event.y > 410 && event.y < 490 && event.x > 970 && event.x < 1050
        && all->settings->nb_sfx > 5)
        all->settings->nb_sfx -= 5;
    else if (event.y > 510 && event.y < 590 && event.x > 970 && event.x < 1050
        && all->settings->nb_mus > 5)
        all->settings->nb_mus -= 5;
    if (event.y > 100 && event.y < 250 && event.x > 100 && event.x < 250)
        all->scene = MAIN_MENU;
    manage_click_option_3(all);
}

void manage_click_option(all_t *all, sfMouseButtonEvent event)
{
    if (event.y > 780 && event.y < 880 && event.x > 1120 && event.x < 1220)
        all->settings->i = 1;
    else if (event.y > 880 && event.y < 980 && event.x > 1120 && event.x < 1220)
        all->settings->k = 1;
    if (event.y > 880 && event.y < 980 && event.x > 1120 && event.x < 1220
        && all->settings->l == 1)
        all->settings->k = 2;
    else if (event.y > 780 && event.y < 880 && event.x > 1120 && event.x < 1220
        && all->settings->j == 1)
        all->settings->i = 2;
    manage_click_option_2(all, event);
}