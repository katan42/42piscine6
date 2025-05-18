/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:53:41 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 14:12:46 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_clues(int grid[4][4], int clues[16]);
int	visible_buildings(int *arr, int size);
int	unique_checker(int grid[4][4], int row, int column, int num);
int	solution(int grid[4][4], int clues[16], int row, int column);
int	*get_clues(char *str, int clues[16]);

//To print the grid values
int	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	num;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			num = grid[i][j] + '0';
			write(1, &num, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

//Initialize grid with zeros
void	initialize_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	clues[16];

	if (argc == 2)
	{
		get_clues(argv[1], clues);
		initialize_grid(grid);
		if (!solution(grid, clues, 0, 0))
			write(1, "No solution\n", 12);
		else
			print_grid(grid);
	}
	else
	{
		write(1, "Invalid Input\n", 14);
	}
	return (0);
}
