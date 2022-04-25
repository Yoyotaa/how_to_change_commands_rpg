/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_strncpy
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest , char const *src , int n)
{
    for (int i = 0; i < n; i++) {
        if (i >= my_strlen(src)) {
            dest[i] = '\0';
            i = n;
        } else {
            dest[i] = src[i];
        }
    }
    return dest;
}
