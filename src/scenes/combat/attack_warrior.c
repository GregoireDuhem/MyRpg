/*
** EPITECH PROJECT, 2020
** attack_warrior.c
** File description:
** function for the attack of the war
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int attack_warrior_1(all_t *all)
{
    all->combat->enemy_stats->life_enemy -= all->combat->stat->attack;
    if (all->combat->enemy_stats->life_enemy <= 0
        && all->combat->stat->level >= 11)
        return VICTORY;
    if (all->combat->enemy_stats->life_enemy <= 0)
        return GAME;
    if (all->combat->enemy_stats->attack - all->combat->stat->defense >= 0)
        all->combat->stat->life -=
                (all->combat->enemy_stats->attack - all->combat->stat->defense);
    all->combat->cooldown_buff -= 1;
    all->combat->cooldown_ult -= 1;
    return COMBAT;
}

int attack_warrior_2(all_t *all)
{
    if (all->combat->stat->level < 2 || all->combat->cooldown_buff > 0)
        return COMBAT;
    all->combat->stat->defense += 10;
    all->combat->cooldown_buff = 2;
    all->combat->cooldown_ult -= 1;
    if (all->combat->enemy_stats->attack - all->combat->stat->defense >= 0)
        all->combat->stat->life -=
                (all->combat->enemy_stats->attack - all->combat->stat->defense);
    return COMBAT;
}

int attack_warrior_3(all_t *all)
{
    if (all->combat->stat->level < 4 || all->combat->cooldown_ult > 0)
        return COMBAT;
    all->combat->cooldown_ult = 3;
    all->combat->cooldown_buff -= 1;
    all->combat->enemy_stats->life_enemy -=
            (all->combat->stat->attack * (all->combat->stat->level / 4));
    if (all->combat->enemy_stats->life_enemy <= 0
        && all->combat->stat->level >= 11)
        return VICTORY;
    if (all->combat->enemy_stats->life_enemy <= 0)
        return GAME;
    if (all->combat->enemy_stats->attack - all->combat->stat->defense >= 0)
        all->combat->stat->life -=
                (all->combat->enemy_stats->attack - all->combat->stat->defense);
    return COMBAT;
}