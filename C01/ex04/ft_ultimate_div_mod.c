/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/01 16:15:34 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	i;
	int	j;

	i = *a / *b;
	j = *a % *b;
	*a = i;
	*b = j;
}
// int main(void)
// {
// 	int x;
// 	int y;

// 	x = 26;
// 	y = 4;
// 	printf("x initial %d\n", x);
// 	printf("y initial %d\n", y);
// 	ft_ultimate_div_mod(&x,&y);
// 	printf("x after (x/y) %d\n", x);
// 	printf("y after (x%%y) %d\n", y);
// }