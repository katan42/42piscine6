/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/08 22:43:35 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_str(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		digit;
	int		baselen;
	long	result;

	i = 0;
	result = 0;
	baselen = 0;
	if (!valid_base(base))
		return (-1);
	while (base[baselen] != '\0')
		baselen++;
	sign = check_str(str, &i);
	digit = get_index(str[i], base);
	while (str[i] != '\0' && digit != -1)
	{
		result = result * baselen + digit;
		i++;
		digit = get_index(str[i], base);
	}
	return (sign * result);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("   ---+--+1234ab567", "0123456789")); 
// 	printf("%d\n", ft_atoi_base("1010", "01"));                        
// 	printf("%d\n", ft_atoi_base("FF", "0123456789ABCDEF"));            
// 	printf("%d\n", ft_atoi_base("en", "ponydash"));                    
// }