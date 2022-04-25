/*
** EPITECH PROJECT, 2021
** LIBMY FUNCTION
** File description:
** maths functions
*/

#include <stdio.h>
#include <stdlib.h>

float power(float x, float n)
{
    return (n == 0) ? 1 : x * power(x, n - 1);
}

float sqroot(int n)
{
    float sqrt = n / 2;

    for (float temp = 0; sqrt != temp; sqrt = ( n / temp + temp) / 2) {
        temp = sqrt;
    }
    return sqrt;
}
