/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 00:29:12 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (nb >= 1)
	{
		i = i * nb;
		nb--;
	}
	return (i);
}

int	main(void)
{
	int	nb1 = 11;
	int	nb2 = 12;
	int	nb3 = 13;
	int	nb4 = 14;
	int	nb5 = 100;
	int	nb6 = 0;
	int	nb7 = -1;
	int	nb8 = 1;
	int	nb0 = 3;

	printf("%d\n", ft_iterative_factorial(nb1));
	printf("%d\n", ft_iterative_factorial(nb2));
	printf("%d\n", ft_iterative_factorial(nb3));
	printf("%d\n", ft_iterative_factorial(nb4));
	printf("%d\n", ft_iterative_factorial(nb5));
	printf("%d\n", ft_iterative_factorial(nb6));
	printf("%d\n", ft_iterative_factorial(nb7));
	printf("%d\n", ft_iterative_factorial(nb8));
	printf("%d\n", ft_iterative_factorial(nb0));
}
