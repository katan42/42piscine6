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

int	check_clues_column_up(int grid[6][6], int clues[24])
{
	int	column[6];
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			column[j] = grid[j][i];
			j++;
		}
		if (clues[i] && visible_buildings(column, 6) != clues[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_column_down(int grid[6][6], int clues[24])
{
	int	column[6];
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 5;
		while (j >= 0)
		{
			column[5 - j] = grid[j][i];
			j--;
		}
		if (clues[i + 6] && visible_buildings(column, 6) != clues[i + 6])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_row_left(int grid[6][6], int clues[24])
{
	int	row[6];
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			row[j] = grid[i][j];
			j++;
		}
		if (clues[i + 12] && visible_buildings(row, 6) != clues[i + 12])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues_row_right(int grid[6][6], int clues[24])
{
	int	row[6];
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 5;
		while (j >= 0)
		{
			row[5 - j] = grid[i][j];
			j--;
		}
		if (clues[i + 18] && visible_buildings(row, 6) != clues[i + 18])
			return (0);
		i++;
	}
	return (1);
}

int	check_clues(int grid[6][6], int clues[24])
{
	if (check_clues_column_up(grid, clues)
		&& check_clues_column_down(grid, clues)
		&& check_clues_row_left(grid, clues)
		&& check_clues_row_right(grid, clues))
		return (1);
	return (0);
}
