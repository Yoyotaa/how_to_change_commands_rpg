/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_put_nbr
*/

void my_putchar(char);
int my_putstr(char const *);

int my_put_nbr(int nb)
{
    int c;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb > 9) {
        c = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(c + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
