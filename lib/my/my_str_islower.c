/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_str_islower
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 97 || str[i] > 122) {
            return 0;
        }
    }
    return 1;
}
