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

int	check_clues_column_up(int grid[5][5], int clues[20])
{
	int	column[5];
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			column[j] = grid[j][i];
			j++;
		}
		if (clues[i] && visible_buildings(column, 5) != clues[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_column_down(int grid[5][5], int clues[20])
{
	int	column[5];
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 4;
		while (j >= 0)
		{
			column[4 - j] = grid[j][i];
			j--;
		}
		if (clues[i + 5] && visible_buildings(column, 5) != clues[i + 5])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_row_left(int grid[5][5], int clues[20])
{
	int	row[5];
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			row[j] = grid[i][j];
			j++;
		}
		if (clues[i + 10] && visible_buildings(row, 5) != clues[i + 10])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_row_right(int grid[5][5], int clues[20])
{
	int	row[5];
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 4;
		while (j >= 0)
		{
			row[4 - j] = grid[i][j];
			j--;
		}
		if (clues[i + 15] && visible_buildings(row, 5) != clues[i + 15])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues(int grid[5][5], int clues[20])
{
	if (check_clues_column_up(grid, clues)
		&& check_clues_column_down(grid, clues)
		&& check_clues_row_left(grid, clues)
		&& check_clues_row_right(grid, clues))
		return (1);
	return (0);
}
