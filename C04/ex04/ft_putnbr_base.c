/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/08 21:41:06 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] <= 32 || base [i] == 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		baselen;

	nb = nbr;
	baselen = 0;
	if (!valid_base(base))
		return ;
	while (base[baselen] != '\0')
		baselen++;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= baselen)
		ft_putnbr_base(nb / baselen, base);
	ft_putchar(base[nb % baselen]);
}

// int main(void)
// {
// 	struct {
// 		int number;
// 		char *base;
// 	} tests[] = {
// 		{42, "0123456789"},       
// 		{-42, "0123456789"},      
// 		{255, "01"},
// 		{18, "0123456789ABCDEF"}, 
// 		{77, "poneyvif"},
// 		{-2147483648, "0123456789ABCDEF"}, // INT_MIN in hex → -80000000
// 		{2147483647, "0123456789ABCDEF"},  // INT_MAX in hex → 7FFFFFFF
// 	};

// 	int i = 0;
// 	int count = sizeof(tests) / sizeof(tests[0]);

// 	while (i < count)
// 	{
// 		printf("Input Number: %d\n", tests[i].number);
// 		printf("Base: \"%s\"\n",(tests[i].base));

// 		ft_putnbr_base(tests[i].number, tests[i].base);
// 		printf("\n\n");
// 		i++;
// 	}
// 	return (0);
// }