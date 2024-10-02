#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int _isnumber(char *str);
char *_callocX(int size);
void multiply(char *num1, char *num2);

int main(int argc, char **argv)
{
    if (argc != 3 || !_isnumber(argv[1]) || !_isnumber(argv[2]))
    {
        printf("Error\n");
        exit(98);
    }

    multiply(argv[1], argv[2]);
    return 0;
}

int _isnumber(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

char *_callocX(int size)
{
    char *res = calloc(size + 1, sizeof(char));
    if (!res)
    {
        printf("Error\n");
        exit(98);
    }
    return res;
}

void multiply(char *num1, char *num2)
{
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int lful = l1 + l2;
    char *res = _callocX(lful);
    int i, j, carry, n1, n2, sum;

    for (i = l1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';
        for (j = l2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = n1 * n2 + (res[i + j + 1] - '0') + carry;
            carry = sum / 10;
            res[i + j + 1] = (sum % 10) + '0';
        }
        res[i + j + 1] += carry;
    }

    i = 0;
    while (i < lful && res[i] == '0')
        i++;

    if (i == lful)
        printf("0\n");
    else
        printf("%s\n", res + i);

    free(res);
}