/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_5x5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloo <cloo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:53:41 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 16:37:15 by cloo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_clues(int grid[6][6], int clues[24]);

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

//To check if numbers repeat on the same row or column
int	unique_checker(int grid[6][6], int row, int column, int num)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (grid[row][i] == num || grid[i][column] == num)
			return (0);
		i++;
	}
	i = 0;
	return (1);
}

//Recursive function to keep retrying
int	solution(int grid[6][6], int clues[24], int row, int column)
{
	int	num;

	if (row == 6)
		return (check_clues(grid, clues));
	if (grid[row][column] != 0)
	{
		if (column == 5)
			return (solution(grid, clues, row + 1, 0));
		else
			return (solution(grid, clues, row, column + 1));
	}
	num = 1;
	while (num <= 6)
	{
		if (unique_checker(grid, row, column, num))
		{
			grid[row][column] = num;
			if ((column == 5 && solution(grid, clues, row + 1, 0))
				|| (column != 5 && solution(grid, clues, row, column + 1)))
				return (1);
			grid[row][column] = 0;
		}
		num++;
	}
	return (0);
}

//Fetch clues from input and store in clues array
int	*get_clues(char *str, int clues[24])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < 24)
	{
		if (str[i] >= '1' && str[i] <= '6')
		{
			clues[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (clues);
}
