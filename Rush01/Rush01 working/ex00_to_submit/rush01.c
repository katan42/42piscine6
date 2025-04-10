/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloo <cloo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:53:41 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 19:27:48 by pchowdry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (str[i] != '\0' && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			clues[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (clues);
}
