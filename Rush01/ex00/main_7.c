/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_5x5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloo <cloo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:53:41 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 16:34:35 by cloo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_clues(int grid[7][7], int clues[28]);
int	visible_buildings(int *arr, int size);
int	unique_checker(int grid[7][7], int row, int column, int num);
int	solution(int grid[7][7], int clues[28], int row, int column);
int	*get_clues(char *str, int clues[28]);

//To print the grid values
int	print_grid(int grid[7][7])
{
	int		i;
	int		j;
	char	num;

	i = 0;
	j = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			num = grid[i][j] + '0';
			write(1, &num, 1);
			if (j < 6)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

//Initialize grid with zeros
void	initialize_grid(int grid[7][7])
{
	int	i;
	int	j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str >= '1' && *str <= '7')
			i++;
		str++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int	grid[7][7];
	int	clues[28];

	if (ft_strlen(argv[1]) > 28)
		write(1, "Error\n", 6);
	else
	{
		if (argc == 2)
		{
			get_clues(argv[1], clues);
			initialize_grid(grid);
			if (!solution(grid, clues, 0, 0))
				write(1, "Error\n", 6);
			else
				print_grid(grid);
		}
		else
		{
			write(1, "Error\n", 6);
		}
	}
	return (0);
}
