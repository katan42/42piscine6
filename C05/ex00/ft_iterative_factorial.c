/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 09:18:16 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	result = 1;
	while (nb >= 1)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}

// int	main(void)
// {
// 	int	nb1 = 11;
// 	int	nb2 = 12;
// 	int	nb3 = 13;
// 	int	nb4 = 14;
// 	int	nb5 = 100;
// 	int	nb6 = 0;
// 	int	nb7 = 1;
// 	int	nb8 = -1;
// 	int	nb0 = 3;

// printf("%d!: %d\n",nb1, ft_iterative_factorial(nb1));
// printf("%d!: %d\n",nb2, ft_iterative_factorial(nb2));
// printf("%d!: %d\n",nb3, ft_iterative_factorial(nb3));
// printf("%d!: %d\n",nb4, ft_iterative_factorial(nb4));
// printf("%d!: %d\n",nb5, ft_iterative_factorial(nb5));
// printf("%d!: %d\n",nb6, ft_iterative_factorial(nb6));
// printf("%d!: %d\n",nb7, ft_iterative_factorial(nb7));
// printf("%d!: %d\n",nb8, ft_iterative_factorial(nb8));
// printf("%d!: %d\n",nb0, ft_iterative_factorial(nb0));
// }
