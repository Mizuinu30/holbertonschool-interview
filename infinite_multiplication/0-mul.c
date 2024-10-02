#include "holberton.h"
#include <stdlib.h>

/* Function to check if the string contains only digits */
int is_digit(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/* Print error and exit */
void print_error(void)
{
    char *error = "Error\n";
    int i = 0;
    
    while (error[i])
    {
        _putchar(error[i]);
        i++;
    }
    exit(98);
}

/* Main function to handle multiplication */
int main(int argc, char *argv[])
{
    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        print_error();

    multiply(argv[1], argv[2]);
    return (0);
}


#include <stdlib.h>

/* Function to multiply two numbers represented as strings */
void multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, carry, n1, n2, sum;
    int *result;

    /* Calculate lengths of the input strings */
    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    /* Allocate memory for the result */
    result = malloc(sizeof(int) * (len1 + len2));
    if (!result)
        exit(98);

    for (i = 0; i < len1 + len2; i++)
        result[i] = 0;

    /* Perform the multiplication */
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';

        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i + j + 1] += carry;
    }

    /* Skip leading zeros and print the result */
    i = 0;
    while (i < len1 + len2 && result[i] == 0)
        i++;

    if (i == len1 + len2)
        _putchar('0');
    else
    {
        for (; i < len1 + len2; i++)
            _putchar(result[i] + '0');
    }
    _putchar('\n');
    free(result);
}
