/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 14:27:47 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

// int	main(void)
// {
// 	printf("0: %d\n", ft_find_next_prime(0));
// 	printf("1: %d\n", ft_find_next_prime(1));
// 	printf("2: %d\n", ft_find_next_prime(2));
// 	printf("3: %d\n", ft_find_next_prime(3));
// 	printf("4: %d\n", ft_find_next_prime(4));
// 	printf("5: %d\n", ft_find_next_prime(5));
// 	printf("10000000: %d\n", ft_find_next_prime(10000000));
// 	printf("-4: %d\n", ft_find_next_prime(-4));
// 	printf("17: %d\n", ft_find_next_prime(17));
// }