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
        if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyEscape\
            && game->mode == &update_menu)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyEscape\
            && game->mode != &update_menu)
            game->mode = &update_menu;
    }
}

//main loop
void process_app(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        if (game->mode != &process_change_commands)
            check_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        
        //Update the current scene once per frame
        game->mode(game);

        sfRenderWindow_display(game->window);
    }
}

//Initialise the commands structure
void init_commands(game_t *game)
{
    /* [STEP2]
    You have to initialise the structure you created

    This structure will store the sfKeys that control the player
    */
}

//Initialise the application
void start(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode mode = {1920, 1080, 32};

    // Creation of the RenderWindow
    game->window = sfRenderWindow_create(mode, "How to change commands :)", sfResize | sfTrue, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);

    //Init the commands structure
    init_commands(game);

    // Creation of the game objects
    game->player = create_object("player", "sprites/player.png", vec(930, 500), create_rect(0, 0, 67, 78));
    game->red_button = create_object("play", "sprites/play.png", vec(660, 200), create_rect(0, 0, 600, 200));
    game->green_button = create_object("settings", "sprites/settings.png", vec(660, 600), create_rect(0, 0, 600, 200));
    game->up = create_object("up", "sprites/up.png", vec(908, 150), create_rect(0, 0, 104, 84));
    game->down = create_object("down", "sprites/down.png", vec(816, 350), create_rect(0, 0, 287, 87));
    game->left = create_object("left", "sprites/left.png", vec(868, 550), create_rect(0, 0, 183, 84));
    game->right = create_object("right", "sprites/right.png", vec(829, 750), create_rect(0, 0, 261, 87));
    game->press = create_object("pr", "sprites/press.png", vec(577, 506), create_rect(0, 0, 766, 108));

    // Loading the scene
    game->mode = &update_menu;
    process_app(game);
}

int main(void)
{
    start();
    return 0;
}
