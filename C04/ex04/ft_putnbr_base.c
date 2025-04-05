/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/05 22:37:11 by ka-tan           ###   ########.fr       */
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
	j = 0;
	while(base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base [i] == 127)
			return (0);
		
	}
	


}



void ft_putnbr_base(int nbr, char *base)
{
	if (base == "" ||)
		return ;

}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

// int	main(void)
// {
// 	ft_putnbr(-2146483648);
// 	ft_putchar('\n');
// 	ft_putnbr(2146483647);
// 	ft_putchar('\n');
// 	ft_putnbr(488);
// 	ft_putchar('\n');
// 	ft_putnbr(0);
// 	ft_putchar('\n');
// }


int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str [i] <= 13))
	{
		str++;
	}
	while (str[i] == '-' || str [i] == '+')
	{
		if (str [i] == '-')
			sign = sign * -1;
		str++;
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