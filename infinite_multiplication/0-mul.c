#include "holberton.h"
#include <stdlib.h>

/**
 * _puts - Prints a string, followed by a new line, to stdout.
 * @str: The string to print.
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
}

/**
 * is_digit_str - Checks if a string consists only of digits.
 * @str: The string to check.
 * Return: 1 if the string consists only of digits, 0 otherwise.
 */
int is_digit_str(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * multiply - Multiplies two numbers represented as strings.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 * Return: Pointer to the result string.
 */
char *multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, total_len, i, j, mul, carry, idx, k, non_zero = 0;
	char *result;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;
	total_len = len1 + len2;
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	for (i = 0; i < total_len; i++)
		result[i] = '0';
	result[total_len] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			idx = i + j + 1;
			mul = (num1[i] - '0') * (num2[j] - '0') +
			      (result[idx] - '0') + carry;
			carry = mul / 10;
			result[idx] = (mul % 10) + '0';
		}
		result[i + j + 1] = ((result[i + j + 1] - '0') + carry) + '0';
	}
	for (k = 0; k < total_len; k++)
	{
		if (result[k] != '0')
		{
			non_zero = 1;
			break;
		}
	}
	if (!non_zero)
	{
		result[0] = '0';
		result[1] = '\0';
	}
	else
	{
		for (i = 0; i + k < total_len; i++)
			result[i] = result[i + k];
		result[i] = '\0';
	}
	return (result);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 * Return: 0 on success, exits with 98 on error.
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3)
	{
		_puts("Error\n");
		exit(98);
	}
	if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
	{
		_puts("Error\n");
		exit(98);
	}
	result = multiply(argv[1], argv[2]);
	if (!result)
	{
		_puts("Error\n");
		exit(98);
	}
	_puts(result);
	_putchar('\n');
	free(result);
	return (0);
}
