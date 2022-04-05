/*
** EPITECH PROJECT, 2020
** init_help.c
** File description:
** function to init the help strcut
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

help_t *create_sprites_help(help_t *help)
{
    help->objects[0] = create_object("img/help_img/slide_1.png",
            (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 0, 0});
    help->objects[1] = create_object("img/help_img/slide_2.png",
            (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 0, 0});
    help->objects[2] = create_object("img/help_img/slide_3.png",
            (sfVector2f) {0, -50}, (sfIntRect) {0, 0, 10, 10});
    help->objects[3] = create_object("img/help_img/slide_4.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 10, 10});

    return help;
}

help_t *init_help(void)
{
    help_t *help = malloc(sizeof(help_t));

    create_sprites_help(help);
    help->slide = 0;
    return help;
}