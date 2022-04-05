/*
** EPITECH PROJECT, 2020
** init_combat.c
** File description:
** function to init the combat struct
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

stats_t *create_stats_struct(all_t *all)
{
    stats_t *stat = malloc(sizeof(stats_t));

    stat->attack = 1;
    stat->life = 15;
    stat->level = 1;
    stat->defense = 1;
    stat->life_max = 15;
    stat->text_life = sfText_create();
    sfText_setString(stat->text_life, "15");
    sfText_setFont(stat->text_life, all->settings->fontopt);
    sfText_setCharacterSize(stat->text_life, 40);
    sfText_setColor(stat->text_life, sfGreen);
    sfText_setPosition(stat->text_life, (sfVector2f){300, 755});
    return stat;
}

enemy_t *init_enemy_stats(all_t *all)
{
    enemy_t *enemy_stats = malloc(sizeof(enemy_t));

    enemy_stats->attack = 1;
    enemy_stats->life_enemy = 10;
    enemy_stats->text_enemy_life = sfText_create();
    sfText_setString(enemy_stats->text_enemy_life, "20");
    sfText_setFont(enemy_stats->text_enemy_life, all->settings->fontopt);
    sfText_setCharacterSize(enemy_stats->text_enemy_life, 40);
    sfText_setColor(enemy_stats->text_enemy_life, sfRed);
    sfText_setPosition(enemy_stats->text_enemy_life, (sfVector2f){1390, 550});
    return enemy_stats;
}

void create_audio_combat(combat_t *combat)
{
    combat->audio[0] = create_audio("sound/combat.ogg");
    combat->audio[1] = create_audio("sound/click.ogg");
}

void create_sprites_combat(combat_t *combat)
{
    combat->objects[0] = create_object("img/Overlay/fight.png",
            (sfVector2f){0, 0},
        (sfIntRect){0, 0, 0, 0});
    combat->objects[1] = create_object("img/character/character_movement.png",
        (sfVector2f){300, 400},
            (sfIntRect){0, 0, 0, 0});
    combat->objects[2] = create_object("img/starting_menu/cursor.png",
            (sfVector2f){0, 0},
            (sfIntRect){0, 0, 10, 10});
    create_sprites_enemy_combat(combat);
}

combat_t *init_combat(all_t *all)
{
    combat_t *combat = malloc(sizeof(combat_t));

    create_sprites_combat(combat);
    create_audio_combat(combat);
    combat->enemy_stat_array = create_array_stat();
    combat->stat = create_stats_struct(all);
    combat->enemy_stats = init_enemy_stats(all);
    combat->mage_1 = sfText_create();
    combat->mage_2 = sfText_create();
    combat->mage_3 = sfText_create();
    combat->warrior_3 = sfText_create();
    combat->warrior_2 = sfText_create();
    combat->warrior_1 = sfText_create();
    set_text_combat_mage(combat, all);
    set_text_combat_warrior(combat, all);
    combat->cooldown_ult = 3;
    combat->cooldown_buff = 1;
    return combat;
}