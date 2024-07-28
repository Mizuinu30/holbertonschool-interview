#include "menger.h"
#include <stdio.h>
#include <math.h>

/* Helper function to determine if a specific cell should be filled or empty */
int isCellFilled(int x, int y)
{
    while (x > 0 || y > 0)
    {
        if (x % 3 == 1 && y % 3 == 1)
        {
            return 0; /* center cell should be empty */
        }
        x /= 3;
        y /= 3;
    }
    return 1; /* filled cell */
}

void menger(int level)
{
    int size = pow(3, level);
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (isCellFilled(i, j))
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}