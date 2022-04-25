/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_size = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0' && i < nb; i++) {
        dest[dest_size + i] = src[i];
    }
    dest[dest_size + i] = '\0';
    return dest;
}
