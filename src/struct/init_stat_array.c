/*
** EPITECH PROJECT, 2020
** init_stat_array.c
** File description:
** function to init the enemy stat array
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int **fill_array_2(int **array_stat)
{
    array_stat[5][0] = 63;
    array_stat[5][1] = 22;
    array_stat[6][0] = 75;
    array_stat[6][1] = 26;
    array_stat[7][0] = 80;
    array_stat[7][1] = 30;
    array_stat[8][0] = 95;
    array_stat[8][1] = 34;
    array_stat[9][0] = 105;
    array_stat[9][1] = 40;
    array_stat[10][0] = 125;
    array_stat[10][1] = 45;

    array_stat[11][0] = 200;
    array_stat[11][1] = 50;
    return array_stat;
}

int **fill_array(int **array_stat)
{
    array_stat[0][0] = 14;
    array_stat[0][1] = 10;
    array_stat[1][0] = 16;
    array_stat[1][1] = 11;
    array_stat[2][0] = 30;
    array_stat[2][1] = 15;
    array_stat[3][0] = 45;
    array_stat[3][1] = 18;
    array_stat[4][0] = 50;
    array_stat[4][1] = 20;
    fill_array_2(array_stat);
    return array_stat;
}

int **create_array_stat(void)
{
    int **array_stat = malloc(sizeof(int *) * 12);

    for (int i = 0; i < 12 ; ++i) {
        array_stat[i] = malloc(sizeof(int) * 2);
    }
    array_stat = fill_array(array_stat);
    return array_stat;
}