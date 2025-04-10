/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clues_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:14:53 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 20:30:33 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	visible_buildings(int *arr, int n);

int	check_clues_column_up(int **grid, int *clues, int n)
{
	int	*column;
	int	i;
	int	j;

	column = (int *)malloc(n * sizeof(int));
	if (!column)
		return (write(1, "malloc failed cup", 17), 1);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			column[j] = grid[j][i];
			j++;
		}
		if (clues[i] && visible_buildings(column, n) != clues[i])
		{
			free(column);
			return (0);
		}
		i++;
	}
	free(column);
	return (1);
}

int	check_clues_column_down(int **grid, int *clues, int n)
{
	int	*column;
	int	i;
	int	j;

	column = (int *)malloc(n * sizeof(int));
	if (!column)
		return (write(1, "malloc failed cdown", 19), 1);
	i = 0;
	while (i < n)
	{
		j = n - 1;
		while (j >= 0)
		{
			column[n - 1 - j] = grid[j][i];
			j--;
		}
		if (clues[i + n] && visible_buildings(column, n) != clues[i + n])
		{
			free(column);
			return (0);
		}
		i++;
	}
	free(column);
	return (1);
}

int	check_clues_row_left(int **grid, int *clues, int n)
{
	int	*row;
	int	i;
	int	j;

	row = (int *)malloc(n * sizeof(int));
	if (!row)
		return (write(1, "malloc failed rl", 14), 1);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			row[j] = grid[i][j];
			j++;
		}
		if (clues[i + (2 * n)]
			&& visible_buildings(row, n) != clues[i + (2 * n)])
		{
			free(row);
			return (0);
		}
		i++;
	}
	free(row);
	return (1);
}

int	check_clues_row_right(int **grid, int *clues, int n)
{
	int	*row;
	int	i;
	int	j;

	row = (int *)malloc(n * sizeof(int));
	if (!row)
		return (write(1, "malloc failed rr", 14), 1);
	i = 0;
	while (i < n)
	{
		j = n - 1;
		while (j >= 0)
		{
			row[n - 1 - j] = grid[i][j];
			j--;
		}
		if (clues[i + (3 * n)]
			&& visible_buildings(row, n) != clues[i + (3 * n)])
		{
			free(row);
			return (0);
		}
		i++;
	}
	free(row);
	return (1);
}

int	check_clues(int **grid, int *clues, int n)
{
	if (check_clues_column_up(grid, clues, n)
		&& check_clues_column_down(grid, clues, n)
		&& check_clues_row_left(grid, clues, n)
		&& check_clues_row_right(grid, clues, n))
		return (1);
	return (0);
}
