/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** process_menu function
*/

#include "rpg.h"

int check_collision_mouse(sfRenderWindow *window, sfSprite *sprite)
{
    touch_t *pos = malloc(sizeof(touch_t));

    pos->mouse_position = sfMouse_getPositionRenderWindow(window);
    pos->sprite_position = sfSprite_getPosition(sprite);
    pos->sprite_size = sfSprite_getLocalBounds(sprite);
    if (pos->mouse_position.x >= pos->sprite_position.x &&\
    pos->mouse_position.x <= pos->sprite_position.x + pos->sprite_size.width) {
        if (pos->mouse_position.y >= pos->sprite_position.y && pos->\
        mouse_position.y <= pos->sprite_position.y + pos->sprite_size.height) {
            free(pos);
            return (1);
        }
    }
    free(pos);
    return (0);
}

int left_click(sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        return (1);
    return (0);
}


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
