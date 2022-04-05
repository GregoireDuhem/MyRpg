/*
** EPITECH PROJECT, 2020
** init_settings.c
** File description:
** function to init the assets and struct of the settings scenes
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

settings_t *set_rect_settings(settings_t *settings)
{
    sfSprite_setTextureRect(settings->objects[2]->sprite,
        (sfIntRect){0, 0, 72, 65});
    sfSprite_setTextureRect(settings->objects[3]->sprite,
        (sfIntRect){0, 0, 72, 65});
    sfSprite_setTextureRect(settings->objects[4]->sprite,
        (sfIntRect){0, 0, 72, 65});
    sfSprite_setTextureRect(settings->objects[5]->sprite,
        (sfIntRect){0, 0, 72, 65});
    sfSprite_setTextureRect(settings->objects[6]->sprite,
        (sfIntRect){0, 0, 100, 100});
    sfSprite_setTextureRect(settings->objects[7]->sprite,
        (sfIntRect){0, 0, 100, 100});
    sfSprite_setTextureRect(settings->objects[8]->sprite,
        (sfIntRect){0, 0, 150, 150});
    return settings;
}

settings_t *create_sprites_settings(settings_t *settings)
{
    settings->objects[0] = create_object("img/settings/bg.jpg",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0});
    settings->objects[1] = create_object("img/starting_menu/cursor.png",
        (sfVector2f){10, 10}, (sfIntRect){0, 0, 0, 0});
    settings->objects[2] = create_object("img/settings/droite.png",
        (sfVector2f){1270, 410}, (sfIntRect){0, 0, 0, 0});
    settings->objects[3] = create_object("img/settings/droite.png",
        (sfVector2f){1270, 510}, (sfIntRect){0, 0, 0, 0});
    settings->objects[4] = create_object("img/settings/gauche.png",
        (sfVector2f){970, 410}, (sfIntRect){0, 0, 0, 0});
    settings->objects[5] = create_object("img/settings/gauche.png",
        (sfVector2f){970, 510}, (sfIntRect){0, 0, 0, 0});
    settings->objects[6] = create_object("img/settings/mute.png",
        (sfVector2f){1120, 780}, (sfIntRect){0, 0, 0, 0});
    settings->objects[7] = create_object("img/settings/mute.png",
        (sfVector2f){1120, 880}, (sfIntRect){0, 0, 0, 0});
    settings->objects[8] = create_object("img/settings/back.png",
        (sfVector2f){100, 100}, (sfIntRect){0, 0, 0, 0});
    settings = set_rect_settings(settings);
    return settings;
}

settings_t *init_settings_struct(void)
{
    settings_t *settings = malloc(sizeof(settings_t));
    settings->fontopt = sfFont_createFromFile("font/arial.ttf");
    settings->sfx_nb = sfText_create();
    settings->mus_nb = sfText_create();
    settings = create_sprites_settings(settings);
    settings->i = 2;
    settings->k = 2;
    settings->nb_mus = 50;
    settings->nb_sfx = 50;
    return settings;
}
