/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** this is a main
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int (*scene_switch[10])(sfRenderWindow *window, all_t *all);

void init_scene_switch(void)
{
    scene_switch[0] = quit_main;
    scene_switch[1] = menu_main;
    scene_switch[2] = setting_main;
    scene_switch[3] = select_main;
    scene_switch[4] = game_main;
    scene_switch[5] = combat_main;
    scene_switch[6] = inventory_main;
    scene_switch[7] = help_main;
    scene_switch[8] = death_main;
    scene_switch[9] = victory_main;
}

int main(int ac, char **av)
{
    all_t *all;

    if (help_flag(ac, av) == 1)
        return 0;
    all = init_all();
    init_scene_switch();
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My RPG", sfClose,
        NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        audio_settings(all);
        sfRenderWindow_display(window);
        if (all->scene == 0)
            break;
        all->scene = scene_switch[all->scene](window, all);
    }
    quit_main(window, all);
    sfRenderWindow_destroy(window);
    return 0;
}
