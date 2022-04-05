/*
** EPITECH PROJECT, 2020
** init_combat.c
** File description:
** function to init the combat struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void set_rect2(combat_t *combat)
{
    sfSprite_setTextureRect(combat->enemy[5]->sprite,
        (sfIntRect){224, 168, 56, 56});
    sfSprite_setTextureRect(combat->enemy[6]->sprite,
        (sfIntRect){788, 0, 56, 56});
    sfSprite_setTextureRect(combat->enemy[7]->sprite,
        (sfIntRect){392, 56, 56, 56});
    sfSprite_setTextureRect(combat->enemy[8]->sprite,
        (sfIntRect){728, 224, 56, 56});
    sfSprite_setTextureRect(combat->enemy[9]->sprite,
        (sfIntRect){840, 336, 56, 56});
    sfSprite_setTextureRect(combat->enemy[10]->sprite,
        (sfIntRect){224, 504, 56, 56});
    set_scale(combat);
}

void set_rect(combat_t *combat)
{
    sfSprite_setTextureRect(combat->enemy[1]->sprite,
        (sfIntRect){844, 0, 56, 56});
    sfSprite_setTextureRect(combat->enemy[0]->sprite,
        (sfIntRect){112, 56, 56, 56});
    sfSprite_setTextureRect(combat->enemy[2]->sprite,
        (sfIntRect){56, 168, 56, 56});
    sfSprite_setTextureRect(combat->enemy[3]->sprite,
        (sfIntRect){112, 56, 56, 56});
    sfSprite_setTextureRect(combat->enemy[4]->sprite,
        (sfIntRect){280, 56, 56, 56});
    set_rect2(combat);
}

void create_sprites_enemy_combat2(combat_t *combat)
{
    combat->enemy[6] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220},
        (sfIntRect){788, 0, 56, 56});
    combat->enemy[7] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220},
        (sfIntRect){392, 56, 56, 56});
    combat->enemy[8] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220},
        (sfIntRect){788, 224, 56, 56});
    combat->enemy[9] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220},
        (sfIntRect){840, 336, 56, 56});
    combat->enemy[10] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1220, 120},
        (sfIntRect){224, 504, 56, 56});
    set_rect(combat);
}

void create_sprites_enemy_combat(combat_t *combat)
{
    combat->enemy[1] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220}, (sfIntRect){844, 0, 56, 56});
    combat->enemy[0] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220}, (sfIntRect){112, 56, 56, 56});
    combat->enemy[2] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220}, (sfIntRect){56, 168, 56, 56});
    combat->enemy[3] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220}, (sfIntRect){504, 168, 56, 56});
    combat->enemy[4] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220}, (sfIntRect){280, 56, 56, 56});
    combat->enemy[5] = create_object("img/enemy/pokemon.png",
        (sfVector2f){1300, 220}, (sfIntRect){224, 168, 56, 56});
    create_sprites_enemy_combat2(combat);
}