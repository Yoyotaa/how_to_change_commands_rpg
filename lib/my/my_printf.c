/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** my_printf
*/

#include <stdarg.h>

void my_putchar(char);
int my_putstr(char const *);
int my_put_nbr(int);
void my_put_unsigned(unsigned int);

static void print_arg(va_list args, char type)
{
    switch (type) {
    case 'd':
        my_put_nbr(va_arg(args, int));
        break;
    case 'i':
        my_put_nbr(va_arg(args, int));
        break;
    case 'c':
        my_putchar(va_arg(args, int));
        break;
    case 's':
        my_putstr(va_arg(args, char *));
        break;
    case 'u':
        my_put_unsigned(va_arg(args, int));
        break;
    default:
        my_putchar(type);
    }
}

int my_printf(char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '%') {
            my_putchar(str[i]);
        } else {
            print_arg(args, str[i + 1]);
            i++;
        }
    }
    return 1;
}
