/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** init of the assets for the game scenes
*/

#include "my.h"
#include "my_rpg_struct.h"
#include "my_rpg.h"

game_t *create_audio_game(game_t *game)
{
    game->audio[0] = create_audio("sound/chill.ogg");
    game->audio[1] = create_audio("sound/click.ogg");
    return game;
}

game_t *create_sprites_game(game_t *game)
{
    game->objects[0] = create_object("img/map/map_RPG.png", (sfVector2f){0, 0},
        (sfIntRect){0, 0, 4416, 4000});
    sfSprite_setOrigin(game->objects[0]->sprite, (sfVector2f){4416, 4000});
    sfSprite_setPosition(game->objects[0]->sprite, (sfVector2f){2880, 1020});
    game->objects[1] = create_object("img/character/character_movement.png",
        (sfVector2f){936, 516}, (sfIntRect){0, 0, 48, 48});
    sfSprite_setScale(game->objects[1]->sprite, (sfVector2f){0.7, 0.7});
    game->objects[2] = create_object("img/starting_menu/cursor.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 10, 10});
    game->objects[3] = create_object("img/Overlay/apple.png",
        (sfVector2f){180, 200}, (sfIntRect){0, 0, 10, 10});
    sfSprite_setScale(game->objects[3]->sprite, (sfVector2f){3.5, 3.5});
    game->dialog[0] = create_object("img/Overlay/dialog1.png",
        (sfVector2f){600, 700}, (sfIntRect){0, 0, 900, 317});
    game->dialog[1] = create_object("img/Overlay/dialog2.png",
        (sfVector2f){600, 700}, (sfIntRect){0, 0, 900, 317});
    game->dialog[2] = create_object("img/Overlay/dialog3.png",
        (sfVector2f){600, 700}, (sfIntRect){0, 0, 900, 317});
    return game;
}

game_t *create_sprites_game2(game_t *game)
{
    game->objects[4] = create_object("img/Overlay/particles.png",
        (sfVector2f){925, 470}, (sfIntRect) {0, 0, 126, 224});
    sfSprite_setScale(game->objects[4]->sprite, (sfVector2f) {0.4, 0.4});
    game->objects[5] = create_object("img/Overlay/shield.png",
        (sfVector2f){360, 200}, (sfIntRect){0, 0, 10, 10});
    sfSprite_setScale(game->objects[5]->sprite, (sfVector2f){3.5, 3.5});
    return game;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->character_move = 0;
    game->xp_bar = 0;
    game->hitbox = sfImage_createFromFile("img/map/mapRPG_hitbox.png");
    game->anim = sfClock_create();
    game->value = 0;
    game->diag_value = 0;
    game->clock = sfClock_create();
    game = create_sprites_game(game);
    game = create_sprites_game2(game);
    game = create_audio_game(game);
    return game;
}