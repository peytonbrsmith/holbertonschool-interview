#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j, stable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				stable = 0;
				break;
			}
			else
			{
				stable = 1;
			}
		}
		if (stable == 0)
		{
			printf("=\n");
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (j)
						printf(" ");
					printf("%d", grid[i][j]);
				}
				printf("\n");
			}
		}
	}
}

/**
 * sandpiles_sum - computes the sum of the sandpiles
 * @grid1: the first grid
 * @grid2: the second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int stable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	print_grid(grid1);
	while (stable == 0)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					stable = 0;
					break;
				}
				else
				{
					stable = 1;
				}
			}
			if (stable == 0)
			{
				grid1 = topple(grid1);
				print_grid(grid1);
			}
		}
	}
}

/**
 * topple - topples the grid
 * @grid: 3x3 grid
 *
 */
int (*topple(int grid[3][3]))[3]
{
	int i, j, grains;
	int new_grid[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			new_grid[i][j] = 0;
			if (grid[i][j] < 4)
				new_grid[i][j] = grid[i][j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				new_grid[i][j] += (grid[i][j] - 4);
				if (i > 0)
					new_grid[i - 1][j] += 1;
				if (i < 2)
					new_grid[i + 1][j] += 1;
				if (j > 0)
					new_grid[i][j - 1] += 1;
				if (j < 2)
					new_grid[i][j + 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = new_grid[i][j];
		}
	}
	return (grid);
}
