/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include "rpg.h"

void change_commands(game_t *game, char *command_to_change)
{
    // init the string "to_change" in the struc commands, and assign him "command_to_change"

    /* [STEP ?]
        Assign "command_to_change" in the to_change variable (from your structure)

        Then, change the scene (game->mode) to &process_change_commands
    */
}

int menu_check_commands(game_t *game, object_t *button)
{
    if (left_click(game->event) == 1) {
        //call the change_commands function
    }
    return (0);
}

text_t *init_text(game_t *game)
{
    text_t *text = malloc(sizeof(text_t));

    /* [STEP ?]
        initialise the text structure with init_font (exmaple below)
    */

    //text->text_up = init_font(game->commands->up, game->up->pos, game->up->rect);

    return (text);
}

void draw_font(text_t *text, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, text->text_up, NULL);
    sfRenderWindow_drawText(window, text->text_down, NULL);
    sfRenderWindow_drawText(window, text->text_left, NULL);
    sfRenderWindow_drawText(window, text->text_right, NULL);
    
}

void update_settings(game_t *game)
{
    //initialise the text structure
    sfRenderWindow_drawSprite(game->window, game->up->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->down->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->left->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->right->sprite, NULL);
    over_button(game->window, game, game->up, &menu_check_commands);
    over_button(game->window, game, game->down, &menu_check_commands);
    over_button(game->window, game, game->left, &menu_check_commands);
    over_button(game->window, game, game->right, &menu_check_commands);
    //draw the font
}
