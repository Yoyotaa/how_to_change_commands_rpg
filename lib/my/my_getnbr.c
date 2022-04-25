/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int negative = 0;
    int result = 0;

    for (; str[i] == 43 || str[i] == 45; i++) {
        if (str[i] == 45) {
            negative++;
        }
    }
    for (; str[i] >= 48 && str[i] <= 57; i++) {
        result = (result * 10) + (str[i] - 48);
    }
    if (negative % 2) {
        result = result * (-1);
    }
    return result;
}
