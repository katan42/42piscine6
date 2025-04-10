/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 08:53:39 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str [i] <= 13))
		i++;
	while (str[i] == '-' || str [i] == '+')
	{
		if (str [i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

// int	main(void)
// {
// 	char str1[] = "1235456";
// 	char str2[] = "    123";
// 	char str3[] = "+456";
// 	char str4[] = "abc1235";
// 	char str5[] = "+45";
// 	char str6[] = "1235abc";
// 	char str7[] = "+-+-+564";
// 	char str8[] = "-+--1235456";

// 	printf("1 ft_atoi: %d   atoi: %d\n", ft_atoi(str1),atoi(str1));
// 	printf("2 ft_atoi: %d   atoi: %d\n", ft_atoi(str2),atoi(str2));
// 	printf("3 ft_atoi: %d   atoi: %d\n", ft_atoi(str3),atoi(str3));
// 	printf("4 ft_atoi: %d   atoi: %d\n", ft_atoi(str4),atoi(str4));
// 	printf("5 ft_atoi: %d   atoi: %d\n", ft_atoi(str5),atoi(str5));
// 	printf("6 ft_atoi: %d   atoi: %d\n", ft_atoi(str6),atoi(str6));
// 	printf("7 ft_atoi: %d\n", ft_atoi(str7));
// 	printf("8 ft_atoi: %d\n", ft_atoi(str8));
// }