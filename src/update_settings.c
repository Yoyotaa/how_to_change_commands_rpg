/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include "rpg.h"

void change_commands(game_t *game, char *command_to_change)
{
    game->commands->to_change = malloc(sizeof(char) * (my_strlen(command_to_change) + 1));
    game->commands->to_change = command_to_change;
    game->mode = &process_change_commands;
}

int menu_check_commands(game_t *game, object_t *button)
{
    if (left_click(game->event) == 1) {
        change_commands(game, button->name);
    }
    return (0);
}

text_t *init_text(game_t *game)
{
    text_t *text = malloc(sizeof(text_t));

    text->text_up = init_font(game->commands->up, game->up->pos, game->up->rect);
    text->text_down = init_font(game->commands->down, game->down->pos, game->down->rect);
    text->text_left = init_font(game->commands->left, game->left->pos, game->left->rect);
    text->text_right = init_font(game->commands->right, game->right->pos, game->right->rect);
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
    text_t *text = init_text(game);

    sfRenderWindow_drawSprite(game->window, game->up->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->down->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->left->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->right->sprite, NULL);
    over_button(game->window, game, game->up, &menu_check_commands);
    over_button(game->window, game, game->down, &menu_check_commands);
    over_button(game->window, game, game->left, &menu_check_commands);
    over_button(game->window, game, game->right, &menu_check_commands);
    draw_font(text, game->window);
}
