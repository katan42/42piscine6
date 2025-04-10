/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clues_5x5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloo <cloo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:14:53 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 16:44:39 by cloo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visible_buildings(int *arr, int size);

int	check_clues_column_up(int grid[7][7], int clues[28])
{
	int	column[7];
	int	i;
	int	j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			column[j] = grid[j][i];
			j++;
		}
		if (clues[i] && visible_buildings(column, 7) != clues[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_column_down(int grid[7][7], int clues[28])
{
	int	column[7];
	int	i;
	int	j;

	i = 0;
	while (i < 7)
	{
		j = 6;
		while (j >= 0)
		{
			column[6 - j] = grid[j][i];
			j--;
		}
		if (clues[i + 7] && visible_buildings(column, 7) != clues[i + 7])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_row_left(int grid[7][7], int clues[28])
{
	int	row[7];
	int	i;
	int	j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			row[j] = grid[i][j];
			j++;
		}
		if (clues[i + 14] && visible_buildings(row, 7) != clues[i + 14])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_row_right(int grid[7][7], int clues[28])
{
	int	row[7];
	int	i;
	int	j;

	i = 0;
	while (i < 7)
	{
		j = 6;
		while (j >= 0)
		{
			row[6 - j] = grid[i][j];
			j--;
		}
		if (clues[i + 21] && visible_buildings(row, 7) != clues[i + 21])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues(int grid[7][7], int clues[28])
{
	if (check_clues_column_up(grid, clues)
		&& check_clues_column_down(grid, clues)
		&& check_clues_row_left(grid, clues)
		&& check_clues_row_right(grid, clues))
		return (1);
	return (0);
}
