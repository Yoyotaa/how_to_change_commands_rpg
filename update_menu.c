/*
** EPITECH PROJECT, 2021
**
** File description:
** main function
*/

#include "rpg.h"

// Update the menu scene
void update_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->red_button->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->green_button->sprite, NULL);
}
