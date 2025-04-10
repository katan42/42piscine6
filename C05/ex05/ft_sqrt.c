/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 10:19:57 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	while (i <= nb)
	{
		if (i > 46340)
			return (0);
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_sqrt(49));
// 	printf("%d\n", ft_sqrt(48));
// 	printf("%d\n", ft_sqrt(0));
// 	printf("%d\n", ft_sqrt(-5));
// 	printf("%d\n", ft_sqrt(2));
// 	printf("%d\n", ft_sqrt(90000));
// 	printf("%d\n", ft_sqrt(2147395600));
// 	printf("%d\n", ft_sqrt(2147483647));
// }
