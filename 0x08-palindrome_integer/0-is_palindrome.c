#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Entry point
 *
 * @n: int
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
    unsigned long rev = 0, num = n;

    while (num > 0)
    {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }
    if (rev == n)
        return (1);
    else
        return (0);
}
