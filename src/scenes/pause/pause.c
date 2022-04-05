/*
** EPITECH PROJECT, 2020
** pause.c
** File description:
** function for the pause
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

void display_pause_sprites(sfRenderWindow *window, all_t *all)
{
    sfRenderWindow_drawSprite(window, all->pause->pause_sprite[0]->sprite,
        NULL);
    sfRenderWindow_drawSprite(window, all->pause->pause_sprite[1]->sprite,
        NULL);
    sfRenderWindow_drawSprite(window, all->pause->pause_sprite[2]->sprite,
        NULL);
    sfRenderWindow_drawSprite(window, all->game->objects[2]->sprite, NULL);
}

int manage_click_pause_menu(all_t *all, sfMouseButtonEvent event)
{
    sfVector2f vector_play = sfSprite_getPosition(
        all->pause->pause_sprite[1]->sprite);
    sfVector2f vector_quit = sfSprite_getPosition(
        all->pause->pause_sprite[2]->sprite);
    sfMusic_stop(all->menu->audio[1]->sound);
    sfMusic_play(all->menu->audio[1]->sound);
    if (event.y > vector_play.y && event.y < (vector_play.y + 110) &&
        event.x > vector_play.x && event.x < (vector_play.x + 530)) {
        all->pause->in_pause = 0;
        return GAME;
    } else if (event.y > vector_quit.y && event.y < (vector_quit.y + 90) &&
        event.x > vector_quit.x && event.x < (vector_quit.x + 490))
        return QUIT;
    return all->scene;
}

int pause_menu_main(sfRenderWindow *window, all_t *all)
{
    display_pause_sprites(window, all);
    return all->scene;
}

int analyse_events_pause_menu(all_t *all, sfEvent *event)
{
    if (all->pause->in_pause == 1) {
        if (all->event.type == sfEvtKeyPressed &&
            sfKeyboard_isKeyPressed(sfKeyP))
            all->pause->in_pause = 0;
        button_animation_pause(all, event->mouseMove);
        if (event->type == sfEvtMouseMoved)
            move_cursor_game(all, event->mouseMove);
        if (event->type == sfEvtMouseButtonPressed) {
            change_button_resume(all, event->mouseButton);
            change_button_quit(all, event->mouseButton);
        } else if (event->type == sfEvtMouseButtonReleased)
            all->scene = manage_click_pause_menu(all, event->mouseButton);
    }
    return all->scene;
}