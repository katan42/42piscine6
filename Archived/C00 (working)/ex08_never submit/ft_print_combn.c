/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:19:29 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/01 15:59:57 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
	if (n >=10)
	{
		print(n / 10);
	}
	ft_putchar((n / 10) + '0');
	ft_putchar((n % 10) + '0');
}

void	print_combination(int i, int j)
{
	print(i);
	if (i == 98 && j == 99)
	{
		return ;
	}
	ft_putchar (',');
	ft_putchar (' ');
}

void	ft_print_combn(int n)
{
	int	i;
	int	j;

	i = 0;
	if (n < 0 || n > 9)
		return;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			print_combination(i, j);
			j++;
		}
		i++;
	}
}
int main(void)
{
	ft_print_comb2();
}

	