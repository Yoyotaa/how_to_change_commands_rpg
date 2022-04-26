/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include "rpg.h"

void change_commands(game_t *game, char *command_to_change)
{
    game->commands->to_change = malloc(sizeof(char) * (my_strlen(command_to_change) + 1));
    game->commands->to_change = command_to_change;
    game->mode = &process_change_commands;
}

int menu_check_commands(game_t *game, object_t *button)
{
    if (left_click(game->event) == 1) {
        change_commands(game, button->name);
    }
    return (0);
}

void update_settings(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->up->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->down->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->left->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->right->sprite, NULL);
    over_button(game->window, game, game->up, &menu_check_commands);
    over_button(game->window, game, game->down, &menu_check_commands);
    over_button(game->window, game, game->left, &menu_check_commands);
    over_button(game->window, game, game->right, &menu_check_commands);
}
