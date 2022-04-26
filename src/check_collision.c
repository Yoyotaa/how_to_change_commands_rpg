/*
** EPITECH PROJECT, 2022
** workshop
** File description:
** Check collision mouse/sprite && sprite/sprite
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
