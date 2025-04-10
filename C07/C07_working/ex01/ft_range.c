/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 22:40:37 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int				*array;
	unsigned int	i;

	i = 0;
	if (min >= max)
	{
		return (NULL);
	}
	array = (int *)malloc((max - min + 1) * sizeof(int));
	if (!array)
	{
		return (0);
	}
	while (min <= max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int	*tab;
// 	int	i = 0;

// 	min = 1;
// 	max = 10;
// 	tab = ft_range(min, max);
// 	while (i <= (max - min))
// 	{
// 		printf("%d, ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free (tab);
// 	return (0);
// }