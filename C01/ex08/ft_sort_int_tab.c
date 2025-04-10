/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:49:24 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/01 19:19:47 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	swapped;

	temp = 0;
	swapped = 1;
	while (swapped != 0)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
	return ;
}

// int main(void)
// {
// 	int tab[] = {8, 0, 7, -7, 5, 1, 3};
// 	int size = sizeof(tab) / sizeof(int);
// 	int i = 0;

// 	printf("array:");
// 	while(i < size)
// 	{ 
// 		printf("%d, ", tab[i]);
// 		i++;
// 	}
// 	ft_sort_int_tab(tab, size);
// 	printf("\narray sort:");
// 	i = 0;
// 	while(i < size)
// 	{ 
// 		printf("%d, ", tab[i]);
// 		i++;
// 	}
// }