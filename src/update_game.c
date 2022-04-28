/*
** EPITECH PROJECT, 2021
**
** File description:
** main function
*/

#include "rpg.h"

void move_player(game_t *game)
{
    /* [STEP 3]
        Now that you created your commands structure,

        You have to modify this function to link the player movement to it:

        The goal is that the inputs rely on the keys stored in your structure (instead of a specific key)
    */
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
    // Reset the position if the player leaves the screen
    game->player->pos.x = (game->player->pos.x > 1920) ? -70 : game->player->pos.x;
    game->player->pos.x = (game->player->pos.x < -70) ? 1920 : game->player->pos.x;
    game->player->pos.y = (game->player->pos.y > 1080) ? -70 : game->player->pos.y;
    game->player->pos.y = (game->player->pos.y < -70) ? 1080 : game->player->pos.y;
    sfSprite_setPosition(game->player->sprite, game->player->pos);
}

// Update the game scene
void update_game(game_t *game)
{
    move_player(game);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
}
