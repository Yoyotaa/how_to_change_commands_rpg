/*
** EPITECH PROJECT, 2021
**
** File description:
** main function
*/

#include "rpg.h"

int menu_buttons(game_t *game, object_t *button)
{
    if (left_click(game->event) == 1) {
        if (strcmp(button->name, "play") == 0)
            game->mode = &update_game;
        if (strcmp(button->name, "settings") == 0)
            game->mode = &update_settings;
    }
    return (0);
}

// Update the menu scene
void update_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->red_button->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->green_button->sprite, NULL);
    over_button(game->window, game, game->red_button, &menu_buttons);
    over_button(game->window, game, game->green_button, &menu_buttons);
}
