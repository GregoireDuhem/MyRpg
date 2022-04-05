/*
** EPITECH PROJECT, 2020
** init_combat_text.c
** File description:
** init the sf text for the combat scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void set_text_combat_mage(combat_t *combat, all_t *all)
{
    sfText_setString(combat->mage_1, "FIRE BALL");
    sfText_setFont(combat->mage_1, all->settings->fontopt);
    sfText_setCharacterSize(combat->mage_1, 40);
    sfText_setColor(combat->mage_1, sfGreen);
    sfText_setPosition(combat->mage_1, (sfVector2f){1150, 750});

    sfText_setString(combat->mage_2, "ARCANE INTEL");
    sfText_setFont(combat->mage_2, all->settings->fontopt);
    sfText_setCharacterSize(combat->mage_2, 40);
    sfText_setColor(combat->mage_2, sfGreen);
    sfText_setPosition(combat->mage_2, (sfVector2f){1150, 835});

    sfText_setString(combat->mage_3, "METEOR");
    sfText_setFont(combat->mage_3, all->settings->fontopt);
    sfText_setCharacterSize(combat->mage_3, 40);
    sfText_setColor(combat->mage_3, sfGreen);
    sfText_setPosition(combat->mage_3, (sfVector2f){1150, 950});
}

void set_text_combat_warrior(combat_t *combat, all_t *all)
{
    sfText_setString(combat->warrior_1, "QUICK SLASH");
    sfText_setFont(combat->warrior_1, all->settings->fontopt);
    sfText_setCharacterSize(combat->warrior_1, 40);
    sfText_setColor(combat->warrior_1, sfGreen);
    sfText_setPosition(combat->warrior_1, (sfVector2f){1150, 750});

    sfText_setString(combat->warrior_2, "SHIELD UP");
    sfText_setFont(combat->warrior_2, all->settings->fontopt);
    sfText_setCharacterSize(combat->warrior_2, 40);
    sfText_setColor(combat->warrior_2, sfGreen);
    sfText_setPosition(combat->warrior_2, (sfVector2f){1150, 835});

    sfText_setString(combat->warrior_3, "EARTH SHATTER");
    sfText_setFont(combat->warrior_3, all->settings->fontopt);
    sfText_setCharacterSize(combat->warrior_3, 40);
    sfText_setColor(combat->warrior_3, sfGreen);
    sfText_setPosition(combat->warrior_3, (sfVector2f){1150, 950});
}