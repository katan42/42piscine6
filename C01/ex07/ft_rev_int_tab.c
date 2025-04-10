/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:49:24 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/01 19:21:11 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab [size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
	return ;
}

// int main(void)
// {
// 	int tab[] = {1, 2, 3, 4, 5, 6, 7};
// 	int size = sizeof(tab) / sizeof(int);
// 	int i = 0;

// 	printf("array:");
// 	while(i < size)
// 	{ 
// 		printf("%d, ", tab[i]);
// 		i++;
// 	}
// 	ft_rev_int_tab(tab, size);
// 	printf("\narray rev:");
// 	i = 0;
// 	while(i < size)
// 	{ 
// 		printf("%d, ", tab[i]);
// 		i++;
// 	}
// }