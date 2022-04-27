/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include "rpg.h"

void assign_command(game_t *game)
{
    // if (my_strcmp(game->commands->to_change, "up") == 0)
    

}

int menu_change(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->event = event;
        if (game->event.type == sfEvtKeyPressed) {
            assign_command(game);
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