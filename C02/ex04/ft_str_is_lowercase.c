/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:23:01 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/01 19:25:43 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_lowercase(char c)
{
	while (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(check_lowercase(str[i])))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	char str[100] = "UPPERCASE";
// 	char str1[100] = "lowercase";
// 	char str2[100] = "i am 123";

// 	printf("%s: %d\n", str, ft_str_is_lowercase(str));
// 	printf("%s: %d\n", str1, ft_str_is_lowercase(str1));
// 	printf("%s: %d\n", str2, ft_str_is_lowercase(str2));
// }