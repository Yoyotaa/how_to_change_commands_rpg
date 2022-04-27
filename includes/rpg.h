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

//structure to work sprite / mouse
typedef struct touch {
    sfVector2i mouse_position;
    sfVector2f sprite_position;
    sfFloatRect sprite_size;
} touch_t;

//structure text
typedef struct text {
    sfText *text_up;
    sfText *text_down;
    sfText *text_left;
    sfText *text_right;
} text_t;

//game object
typedef struct object {
    char *name;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} object_t;

//structure commands
typedef struct commands {
    int up;
    int down;
    int left;
    int right;
    char *to_change;
} command_t;

//game structure
typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    object_t *red_button;
    object_t *green_button;
    object_t *player;
    object_t *up;
    object_t *down;
    object_t *left;
    object_t *right;
    object_t *press;
    command_t *commands;
    void (*mode)(struct game *game);
} game_t;

sfVector2f vec(float x, float y);
sfIntRect create_rect(int top, int left, int width, int height);
object_t *create_object(char *name, char *path, sfVector2f pos, sfIntRect rect);
void update_menu(game_t *game);
void update_game(game_t *game);
int check_collision_mouse(sfRenderWindow *window, sfSprite *sprite);
int left_click(sfEvent event);
int over_button(sfRenderWindow *window, game_t *game, object_t *button, int (*function)(game_t *game, object_t *button));
int menu_buttons(game_t *game, object_t *button);
void update_settings(game_t *game);
void process_change_commands(game_t *game);
sfText *init_font(char command, sfVector2f v, sfIntRect rect);
