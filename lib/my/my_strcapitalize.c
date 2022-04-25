/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    if (str[0] >= 97 && str[0] <= 122) {
        str[0] -= 32;
    }
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] > 47 && str[i + 1] >= 65 && str[i + 1] <= 90) {
            str[i + 1] += 32;
        }
        if (str[i] <= 47 && str[i + 1] >= 97 && str[i + 1] <= 122) {
            str[i + 1] -= 32;
        }
    }
    return str;
}
