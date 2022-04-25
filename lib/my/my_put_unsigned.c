/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_put_unsigned
*/

void my_putchar(char);

void my_put_unsigned(unsigned int nb)
{
    int c;

    nb %= 4294967296;
    if (nb > 9) {
        c = nb % 10;
        my_put_unsigned(nb / 10);
        my_putchar(c + 48);
    } else {
        my_putchar(nb + 48);
    }
}
