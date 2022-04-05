/*
** EPITECH PROJECT, 2020
** attack_mage.c
** File description:
** function for the mage attacks
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int attack_mage_1(all_t *all)
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

int attack_mage_2(all_t *all)
{
    if (all->combat->stat->level < 2 || all->combat->cooldown_buff > 0)
        return COMBAT;
    all->combat->cooldown_buff = 2;
    all->combat->cooldown_ult -= 1;
    all->combat->stat->attack += 10;
    if (all->combat->enemy_stats->attack - all->combat->stat->defense >= 0)
        all->combat->stat->life -=
                (all->combat->enemy_stats->attack - all->combat->stat->defense);
    return COMBAT;
}

int attack_mage_3(all_t *all)
{
    if (all->combat->stat->level < 4 || all->combat->cooldown_ult > 0)
        return COMBAT;
    all->combat->cooldown_ult = 3;
    all->combat->cooldown_buff -= 1;
    all->combat->enemy_stats->life_enemy -=
            (all->combat->stat->attack * (all->combat->stat->level / 2));
    if (all->combat->enemy_stats->life_enemy <= 0
        && all->combat->stat->level >= 11)
        return VICTORY;
    if (all->combat->enemy_stats->life_enemy <= 0)
        return VICTORY;
    if (all->combat->enemy_stats->attack - all->combat->stat->defense >= 0)
        all->combat->stat->life -=
                (all->combat->enemy_stats->attack - all->combat->stat->defense);
    return COMBAT;
}