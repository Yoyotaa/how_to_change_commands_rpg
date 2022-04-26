/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** process_menu function
*/

#include "rpg.h"

void check_for_over(object_t *button, game_t *game)
{
    if (check_collision_mouse(game->window, button->sprite) != 1)
        button->rect.left = 0;
}

int over_button(sfRenderWindow *window, game_t *game, object_t *button, int (*function)(game_t *game, object_t *button))
{
        if (check_collision_mouse(window, button->sprite) == 1) {
            button->rect.left = button->rect.width;
            sfSprite_setTextureRect(button->sprite, button->rect);
            if (function(game, button)) {
                return (1);
            }
        } else
            check_for_over(button, game);
        sfSprite_setTextureRect(button->sprite, button->rect);
    return (0);
}
