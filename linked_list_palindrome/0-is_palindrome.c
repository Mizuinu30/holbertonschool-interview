#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a
 *	palindrome
 */
int is_palindrome(unsigned long n)
{
    int num = n;
    int digit, rev_num;

    rev_num = 0;
    while (n > 0)
    {
        digit = n % 10;
        rev_num = (rev_num * 10) + digit;
        n /= 10;
    }
    if (rev_num == num)
        return (0);
    return (1);
}
