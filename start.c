/*
** EPITECH PROJECT, 2021
**
** File description:
** main function
*/

#include "rpg.h"

void check_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->event = event;
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window);
    }
}

//main loop
void process_app(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        check_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        
        //Update the current scene once per frame (function pointer)
        game->mode(game);

        sfRenderWindow_display(game->window);
    }
}

//Initialise the application
void start(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode mode = {1920, 1080, 32};

    // Creation of the RenderWindow
    game->window = sfRenderWindow_create(mode, "How to change commands :)", sfResize | sfTrue, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);

    // Creation of the game objects
    game->player = create_object("sprites/player.png", vec(930, 500), create_rect(0, 0, 67, 78));
    game->red_button = create_object("sprites/red_button.png", vec(660, 200), create_rect(0, 0, 600, 200));
    game->green_button = create_object("sprites/green_button.png", vec(660, 600), create_rect(0, 0, 600, 200));

    // Loading the scene
    game->mode = &update_menu;
    process_app(game);
}

int main(void)
{
    start();
    return 0;
}
