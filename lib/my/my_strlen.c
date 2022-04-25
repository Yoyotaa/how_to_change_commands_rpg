/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        len ++;
    }
    return len;
}
