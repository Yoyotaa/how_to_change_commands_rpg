/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_font function
*/

#include "rpg.h"

char *fill_str(int command)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = command;
    str[1] = '\0';
    return (str);
}

char *str_key(int command)
{
    switch (command) {
    case 71:
        return ("KEY_LEFT");
    case 72:
        return ("KEY_RIGHT");
    case 73:
        return ("KEY_UP");
    case 74:
        return ("KEY_DOWN");
    }
    return ("SELECT ANOTHER KEY");
}

char *f_key(int command)
{
    switch (command) {
    case 85:
        return ("F1");
    case 86:
        return ("F2");
    case 87:
        return ("F3");
    case 88:
        return ("F4");
    case 89:
        return ("F5");
    case 90:
        return ("F6");
    case 91:
        return ("F7");
    case 92:
        return ("F8");
    case 93:
        return ("F9");
    case 94:
        return ("F10");
    }
    return ("F11");
}

char *my_strcommands(int command)
{
    if (command >= 0 && command <= 25)
        return (fill_str(command + 65));
    if (command > 25 && command <= 35)
        return (fill_str(command + 22));
    if (command >= 71 && command <= 74)
        return (str_key(command));
    if (command >= 85 && command <= 99)
        return (f_key(command));
    return ("SELECT ANOTHER KEY");
}

sfText *init_font(char command, sfVector2f v, sfIntRect rect)
{
    char *to_print = my_strcommands(command);
    sfVector2f vectext;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font/bellerose/Bellerose.ttf");

    vectext.x = v.x + rect.width + 20;
    vectext.y = v.y;
    sfText_setPosition(text, vectext);
    sfText_setString(text, to_print);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfRed);
    return (text);
}
