#include "lists.h"

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: grid to be freed
 * @height: height of grid
 * Return: 0
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height == 0)
		return;
	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
