/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:23:01 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/01 19:29:50 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;
	int				check_char;

	i = 0;
	check_char = 1;
	while (str[i] != '\0')
	{
		if (check_char == 1 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (check_char == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= '0' && str[i] <= '9' )
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			check_char = 0;
		else
			check_char = 1;
		i++;
	}
	return (str);
}

// int main(void)
// {
// 	char str[100] = "salut, comment TU vas ?";

// 	printf("%s\n",ft_strcapitalize(str));
// }