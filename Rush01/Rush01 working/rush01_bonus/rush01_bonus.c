/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:53:41 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 20:25:11 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_clues(int **grid, int *clues, int n);

//To find the number of buildings visibles from a specific row or column
int	visible_buildings(int *arr, int n)
{
	int	tallest;
	int	visible;
	int	i;

	tallest = 0;
	visible = 0;
	i = 0;
	while (i < n)
	{
		if (arr[i] > tallest)
		{
			tallest = arr[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

//To check if numbers repeat on the same row or column
int	unique_checker(int **grid, int row, int column, int num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (grid[row][i] == num || grid[i][column] == num)
			return (0);
		i++;
	}
	i = 0;
	return (1);
}

//Recursive function to keep retrying
int	solution(int **grid, int *clues, int row, int column, int n)
{
	int	num;

	if (row == n)
		return (check_clues(grid, clues, n));
	if (grid[row][column] != 0)
	{
		if (column == n - 1)
		{
			return (solution(grid, clues, row + 1, 0, n));
		}
		else
		{
			return (solution(grid, clues, row, column + 1, n));
		}
	}
	num = 1;
	while (num <= n)
	{
		if (unique_checker(grid, row, column, num, n))
		{
			grid[row][column] = num;
			if ((column == n - 1
					&& solution(grid, clues, row + 1, 0, n))
				|| (column != n - 1
					&& solution(grid, clues, row, column + 1, n)))
			{
				return (1);
			}
			grid[row][column] = 0;
		}
		num++;
	}
	return (0);
}

//Fetch clues from input and store in clues array
int	*get_clues(char *str, int *clues, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < (n * 4))
	{
		if (str[i] >= '1' && str[i] <= ('0' + n))
		{
			clues[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (clues);
}
