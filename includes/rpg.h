/*
** EPITECH PROJECT, 2021
** ...
** File description:
** global header
*/

#include "libmy.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

//game object
typedef struct object {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} object_t;

//game structure
typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    object_t *red_button;
    object_t *green_button;
    object_t *player;
    void (*mode)(struct game *game);
} game_t;

sfVector2f vec(float x, float y);
sfIntRect create_rect(int top, int left, int width, int height);
object_t *create_object(char *path, sfVector2f pos, sfIntRect rect);
void update_menu(game_t *game);
void update_game(game_t *game);
