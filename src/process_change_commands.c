/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include "rpg.h"

void new_c(game_t *game)
{
    if (my_strcmp(game->commands->to_change, "up") == 0)
        game->commands->up = game->event.key.code;
    if (my_strcmp(game->commands->to_change, "down") == 0)
        game->commands->down = game->event.key.code;
    if (my_strcmp(game->commands->to_change, "left") == 0)
        game->commands->left = game->event.key.code;
    if (my_strcmp(game->commands->to_change, "right") == 0)
        game->commands->right = game->event.key.code;
}

int menu_change(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->event = event;
        if (game->event.type == sfEvtKeyPressed) {
            new_c(game);
            game->mode = &update_settings;
        }
    }
    return (0);
}


void process_change_commands(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->press->sprite, NULL);
    menu_change(game);
}