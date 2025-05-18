/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rush01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:53:41 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 14:12:54 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_clues(int grid[4][4], int clues[16]);

//To find the number of buildings visibles from a specific row or column
int	visible_buildings(int *arr, int size)
{
	int	tallest;
	int	visible;
	int	i;

	tallest = 0;
	visible = 0;
	i = 0;
	while (i < size)
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
/*
//Check if clue conditions are satisfied
int	check_clues(int grid[4][4], int clues[16])
{
	int	row[4];
	int	column[4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			column[j] = grid[j][i];
			j++;
		}
		if (clues[i] && visible_buildings(column, 4) != clues[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 3;
		while (j >= 0)
		{
			column[3 - j] = grid[j][i];
			j--;
		}
		if (clues[i + 4] && visible_buildings(column, 4) != clues[i + 4])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row[j] = grid[i][j];
			j++;
		}
		if (clues[i + 8] && visible_buildings(row, 4) != clues[i + 8])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 3;
		while (j >= 0)
		{
			row[3 - j] = grid[i][j];
			j--;
		}
		if (clues[i + 12] && visible_buildings(row, 4) != clues[i + 12])
			return (0);
		i++;
	}
	return (1);
}
*/

//To check if numbers repeat on the same row or column
int	unique_checker(int grid[4][4], int row, int column, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][column] == num)
			return (0);
		i++;
	}
	i = 0;
	return (1);
}

//Recursive function to keep retrying
int	solution(int grid[4][4], int clues[16], int row, int column)
{
	int	num;

	if (row == 4)
		return (check_clues(grid, clues));
	if (grid[row][column] != 0)
	{
		if (column == 3)
			return (solution(grid, clues, row + 1, 0));
		else
			return (solution(grid, clues, row, column + 1));
	}
	num = 1;
	while (num <= 4)
	{
		if (unique_checker(grid, row, column, num))
		{
			grid[row][column] = num;
			if ((column == 3 && solution(grid, clues, row + 1, 0))
				|| (column != 3 && solution(grid, clues, row, column + 1)))
				return (1);
			grid[row][column] = 0;
		}
		num++;
	}
	return (0);
}

//Fetch clues from input and store in clues array
int	*get_clues(char *str, int clues[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			clues[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (clues);
}
