#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: stable sandpile to add to grid2
 * @grid2: stable sandpile to add to grid1
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
	while (is_stable(grid1) == 0)
		topple_sandpiles(grid1);
}

/**
 * is_stable - verifies if the sandpile is stable
 * @grid1: sandpile to verify
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple_sandpiles - topples the sandpile
 * @grid1: sandpile to topple
 */
void topple_sandpiles(int grid1[3][3])
{
	int i, j;
	int sand_grid1[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	printf("=\n");
	print_grid1(grid1);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i >= 0 && i < 2)
					sand_grid1[i + 1][j] += 1;
				if (i > 0 && i <= 2)
					sand_grid1[i - 1][j] += 1;
				if (j >= 0 && j < 2)
					sand_grid1[i][j + 1] += 1;
				if (j > 0 && j <= 2)
					sand_grid1[i][j - 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += sand_grid1[i][j];
	}
}

/**
 * print_grid1 - prints the sandpile
 * @grid1: sandpile to be printed
 */
void print_grid1(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}
