/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/04 16:16:19 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	str_count(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	if (nb <= 0)
	{
		return (dest);
	}
	i = 0;
	j = str_count(dest);
	while (src[i] != '\0' && i < nb)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

//strncat limits how much is copied and adds a null terminator at the back
// int	main(int argc, char **argv)
// {
// 	char	dest[9];
// 	char	src[20];

// 	if (argc == 3)
// 	{
// 		strcpy(dest, argv[1]);
// 		strcpy(src, argv[2]);
// 		printf("ft_strncat: %s\n", ft_strncat(dest, src, 3));
// 		strcpy(dest, argv[1]);
// 		strcpy(src, argv[2]);
// 		printf("strncat: %s\n", strncat(dest, src, 3));
// 	}
// }