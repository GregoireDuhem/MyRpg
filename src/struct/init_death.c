/*
** EPITECH PROJECT, 2020
** init_death.c
** File description:
** function to init the death scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

death_t *create_audio_death(death_t *death)
{
    death->audio[0] = create_audio("sound/death.ogg");
    death->audio[1] = create_audio("sound/click.ogg");
    return death;
}

death_t *create_sprites_death(death_t *death)
{
    death->objects[0] = create_object("img/Overlay/death.png",
            (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    death->objects[1] = create_object("img/starting_menu/cursor.png",
            (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 10, 10});
    return death;
}

death_t *init_death(void)
{
    death_t *death = malloc(sizeof(death_t));

    death = create_audio_death(death);
    death = create_sprites_death(death);
    death->light_on = 0;
    return death;
}