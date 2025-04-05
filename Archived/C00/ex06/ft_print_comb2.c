/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:19:29 by ka-tan            #+#    #+#             */
/*   Updated: 2025/03/27 20:43:56 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_character(char c)
{
	write (1, &c, 1);
}

void	print_two_digit(int n)
{
	print_character((n / 10) + '0');
	print_character((n % 10) + '0');
}

void	print_combination(int i, int j)
{
	print_two_digit(i);
	print_character (' ');
	print_two_digit(j);
	if (i == 98 && j == 99)
	{
		return ;
	}
	print_character (',');
	print_character (' ');
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
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
// int main(void)
// {
// 	ft_print_comb2();
// }