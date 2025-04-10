/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloo <cloo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:14:53 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 15:38:00 by cloo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visible_buildings(int *arr, int size);

int	check_clues_column_up(int grid[4][4], int clues[16])
{
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
	return (1);
}

int	check_clues_column_down(int grid[4][4], int clues[16])
{
	int	column[4];
	int	i;
	int	j;

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
	return (1);
}

int	check_clues_row_left(int grid[4][4], int clues[16])
{
	int	row[4];
	int	i;
	int	j;

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
	return (1);
}

int	check_clues_row_right(int grid[4][4], int clues[16])
{
	int	row[4];
	int	i;
	int	j;

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

int	check_clues(int grid[4][4], int clues[16])
{
	if (check_clues_column_up(grid, clues)
		&& check_clues_column_down(grid, clues)
		&& check_clues_row_left(grid, clues)
		&& check_clues_row_right(grid, clues))
		return (1);
	return (0);
}
