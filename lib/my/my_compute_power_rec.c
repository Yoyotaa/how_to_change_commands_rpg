/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    if (nb * my_compute_power_rec(nb, p - 1) <= 2147483647) {
        return nb * my_compute_power_rec(nb, p - 1);
    }
    return 0;
}
