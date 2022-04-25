/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    if (nb <= 0) {
        return 0;
    }
    for (int i = 1; i * i <= nb; i++) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
