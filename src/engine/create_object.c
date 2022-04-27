/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** create_object
*/

#include "rpg.h"

//return a vector
sfVector2f vec(float x, float y)
{
    sfVector2f init;

    init.x = x;
    init.y = y;
    return(init);
}

//create and return a rect (sfIntRect)
sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect init;

    init.top = top;
    init.left = left;
    init.width = width;
    init.height = height;
    return(init);
}

//create and return a game object (object_t)
object_t *create_object(char *name, char *path, sfVector2f pos, sfIntRect rect)
{
    object_t *object = malloc(sizeof(game_t));

    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    object->pos = pos;
    object->name = name;
    object->rect = rect;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, rect);
    sfSprite_setPosition(object->sprite, object->pos);
    return (object);
}
