/*
** EPITECH PROJECT, 2021
**
** File description:
** main function
*/

#include "rpg.h"

/*
If you already created your "commands" structure,

You have to modify this function to link the player movement to it:

The goal is that the inputs rely on the keys stored in your structure
*/
void move_player(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        game->player->pos.y -= 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        game->player->pos.x += 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        game->player->pos.y += 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        game->player->pos.x -= 5;
    }
    sfSprite_setPosition(game->player->sprite, game->player->pos);
}

// Update the game scene
void update_game(game_t *game)
{
    move_player(game);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
}
