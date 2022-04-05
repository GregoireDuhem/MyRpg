/*
** EPITECH PROJECT, 2020
** starting_menu.c
** File description:
** files for the starting menu scene
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

int manage_click_menu_2(all_t *all, sfMouseButtonEvent event)
{
    sfVector2f vector_help = sfSprite_getPosition(
        all->menu->objects[3]->sprite);
    sfVector2f vector_settings = sfSprite_getPosition(
        all->menu->objects[5]->sprite);

    sfMusic_stop(all->menu->audio[1]->sound);
    sfMusic_play(all->menu->audio[1]->sound);

    if (event.y > vector_settings.y && event.y < (vector_settings.y + 200) &&
        event.x > vector_settings.x && event.x < (vector_settings.x + 200))
        return SETTINGS;
    else if (event.y > vector_help.y && event.y < (vector_help.y + 150) &&
        event.x > vector_help.x && event.x < (vector_help.x + 400))
        return HELP;
    return 1;
}

int manage_click_menu(all_t *all, sfMouseButtonEvent event)
{
    sfVector2f vector_play = sfSprite_getPosition(
        all->menu->objects[2]->sprite);
    sfVector2f vector_quit = sfSprite_getPosition(
        all->menu->objects[4]->sprite);

    sfMusic_stop(all->menu->audio[1]->sound);
    sfMusic_play(all->menu->audio[1]->sound);
    if (event.y > vector_play.y && event.y < (vector_play.y + 150) &&
        event.x > vector_play.x && event.x < (vector_play.x + 400))
        return CHAMP_SELECT;
    else if (event.y > vector_quit.y && event.y < (vector_quit.y + 150) &&
        event.x > vector_quit.x && event.x < (vector_quit.x + 400))
        return QUIT;

    return manage_click_menu_2(all, event);
}

void move_cursor_menu(all_t *all, sfMouseMoveEvent moveEvent)
{
    sfVector2f vector2F;
    vector2F.y = (float)moveEvent.y;
    vector2F.x = (float)moveEvent.x;
    sfSprite_setPosition(all->menu->objects[1]->sprite, vector2F);
    button_animation(all, vector2F);
}

int analyse_events_menu(all_t *all, sfEvent *event)
{
    all->scene = MAIN_MENU;
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        all->scene = QUIT;
    if (event->type == sfEvtMouseButtonPressed)
        all->scene = manage_click_menu(all, event->mouseButton);
    else if (event->type == sfEvtMouseMoved)
        move_cursor_menu(all, event->mouseMove);
    return all->scene;
}

int menu_main(sfRenderWindow *window, all_t *all)
{
    set_cursor_on_mouse(window, all->menu->objects[1]->sprite);
    sfMusic_play(all->menu->audio[0]->sound);
    if (all->settings->k == 1)
        sfMusic_setVolume(all->menu->audio[0]->sound, 0);
    while (all->scene == MAIN_MENU) {
        display_menu_sprites(window, all);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &all->event)) {
            all->scene = analyse_events_menu(all, &all->event);
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    sfMusic_stop(all->menu->audio[0]->sound);
    return all->scene;
}
