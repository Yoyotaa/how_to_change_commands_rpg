/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_putstr
*/

void my_putchar(char);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
