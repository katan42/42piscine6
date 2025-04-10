/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:53:41 by pchowdry          #+#    #+#             */
/*   Updated: 2025/03/30 20:25:36 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	check_clues(int **grid, int *clues, int n);
int	visible_buildings(int *arr, int n);
int	unique_checker(int **grid, int row, int column, int num, int n);
int	solution(int **grid, int *clues, int row, int column, int n);
int	*get_clues(char *str, int *clues, int n);

//To print the grid values
int	print_grid(int **grid, int n)
{
	int		i;
	int		j;
	char	num;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			num = grid[i][j] + '0';
			write(1, &num, 1);
			if (j < n - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	grid[0][0] = n;
	return (0);
}

//Initialize grid with zeros
void	initialize_grid(int **grid, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
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
		if (*str >= '1' && *str <= '9')
			i++;
		str++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int		**grid;
	int		*clues;
	int		n;
	char	*temp;
	int		i;

	n = ft_strlen(argv[1]) / 4;
	clues = (int *)malloc(4 * n * sizeof(int));
	if (!clues)
		return (write(1, "malloc failed", 13), 1);
	grid = (int **)malloc(n * sizeof(int *));
	if (!grid)
		return (free(clues), write(1, "malloc failed grid", 18), 1);
	i = 0;
	while (i < n)
	{
		grid[i] = (int *)malloc(n * sizeof(int));
		if (!grid[i])
		{
			while (i > 0)
				free(grid[i--]);
			free(grid);
			free(clues);
			return (write(1, "malloc failed row", 17), 1);
		}
		i++;
	}
	if (ft_strlen(argv[1]) % 4 != 0 || ft_strlen(argv[1]) < 16
		|| ft_strlen(argv[1]) > 36)
	{
		write(1, "Erro1\n", 6);
		i = 0;
		while (i < n)
			free(grid[i++]);
		free(grid);
		free(clues);
		return (0);
	}
	temp = argv[1];
	while (*temp != '\0')
	{
		if (*temp - '0' > n)
		{
			write(1, "Erro2\n", 6);
			i = 0;
			while (i < n)
				free(grid[i++]);
			free(grid);
			free(clues);
			return (0);
		}
		temp++;
	}
	if (argc == 2)
	{
		get_clues(argv[1], clues, n);
		initialize_grid(grid, n);
		if (!solution(grid, clues, 0, 0, n))
			write(1, "Erro3\n", 6);
		else
			print_grid(grid, n);
	}
	else
	{
		write(1, "Erro4\n", 6);
	}
	i = 0;
	while (i < n)
		free(grid[i++]);
	free(grid);
	free(clues);
	return (0);
}
