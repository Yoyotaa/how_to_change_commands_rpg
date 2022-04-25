/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_find_prime_sup
*/

int my_is_prime(int);

int my_find_prime_sup(int nb)
{
    for (; nb <= 2147483647; nb++) {
        if (my_is_prime(nb)) {
            return nb;
        }
    }
    return 0;
}
