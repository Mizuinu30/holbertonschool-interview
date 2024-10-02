#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "holberton.h"

void error(char **calculation, char *final)
{
    printf("Error\n");
    if (calculation)
        free(calculation);
    if (final)
        free(final);
    exit(98);
}

int digit_check(char *number)
{
    int i = 0;

    while (number[i])
    {
        if (!isdigit(number[i]))
            return (0);
        i++;
    }
    return (i);
}

void set_max_min(unsigned int digit_count1, unsigned int digit_count2,
                 unsigned int *max_digit, unsigned int *min_digit,
                 char **num1, char **num2, char *arg1, char *arg2)
{
    if (digit_count1 >= digit_count2)
    {
        *max_digit = digit_count1;
        *min_digit = digit_count2;
        *num1 = arg1;
        *num2 = arg2;
    }
    else
    {
        *max_digit = digit_count2;
        *min_digit = digit_count1;
        *num1 = arg2;
        *num2 = arg1;
    }
}

char **create_double(unsigned int row_size, unsigned int column_size)
{
    char **calculation;
    unsigned int i, j;

    calculation = malloc(row_size * sizeof(char *));
    if (!calculation)
        error(NULL, NULL);

    for (i = 0; i < row_size; i++)
    {
        calculation[i] = malloc(column_size * sizeof(char));
        if (!calculation[i])
            error(calculation, NULL);
        for (j = 0; j < column_size; j++)
            calculation[i][j] = '0';
    }
    return (calculation);
}

char *create_final(unsigned int size)
{
    char *final;
    unsigned int i;

    final = malloc(size * sizeof(char));
    if (!final)
        error(NULL, NULL);

    for (i = 0; i < size; i++)
        final[i] = '0';

    return (final);
}

char *final_realloc(char *final, unsigned int size)
{
    char *new_final;
    unsigned int i;

    new_final = malloc(size * sizeof(char));
    if (!new_final)
        error(NULL, final);

    for (i = 0; i < size; i++)
        new_final[i] = final[i];

    free(final);
    return (new_final);
}

void multiply(char **calculation, unsigned int max_digit, unsigned int min_digit,
              char *num1, char *num2)
{
    unsigned int i, j;
    int carry, product, sum;

    for (i = min_digit; i > 0; i--)
    {
        carry = 0;
        for (j = max_digit; j > 0; j--)
        {
            product = (num2[i - 1] - '0') * (num1[j - 1] - '0') + carry;
            sum = (calculation[min_digit - i][max_digit - j] - '0') + product;
            carry = sum / 10;
            calculation[min_digit - i][max_digit - j] = (sum % 10) + '0';
        }
        if (carry > 0)
            calculation[min_digit - i][max_digit - j] = carry + '0';
    }
}

void add(char **calculation, char *final, unsigned int max_digit,
         unsigned int min_digit)
{
    unsigned int i, j;
    int carry, sum;

    for (i = 0; i < min_digit; i++)
    {
        carry = 0;
        for (j = 0; j < max_digit + min_digit; j++)
        {
            sum = (final[j] - '0') + (calculation[i][j] - '0') + carry;
            carry = sum / 10;
            final[j] = (sum % 10) + '0';
        }
        if (carry > 0)
            final[j] = carry + '0';
    }
}

void print_final(char *final)
{
    int i = 0;

    while (final[i] == '0')
        i++;

    if (final[i] == '\0')
        _putchar('0');
    else
    {
        while (final[i] != '\0')
        {
            _putchar(final[i]);
            i++;
        }
    }
    _putchar('\n');
}

int main(int argc, char **argv)
{
    unsigned int digit_count1, digit_count2, max_digit, min_digit;
    char *num1 = NULL, *num2 = NULL, **calculation = NULL, *final = NULL;

    if (argc != 3)
        error(NULL, NULL);

    digit_count1 = digit_check(argv[1]);
    digit_count2 = digit_check(argv[2]);

    if (digit_count1 == 0 || digit_count2 == 0)
        error(NULL, NULL);

    set_max_min(digit_count1, digit_count2, &max_digit, &min_digit, &num1, &num2, argv[1], argv[2]);

    calculation = create_double(min_digit, max_digit + min_digit);
    final = create_final(max_digit + min_digit);

    multiply(calculation, max_digit, min_digit, num1, num2);
    add(calculation, final, max_digit, min_digit);
    print_final(final);

    free(final);
    for (unsigned int i = 0; i < min_digit; i++)
        free(calculation[i]);
    free(calculation);

    return (0);
}
