/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/04 16:16:10 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(int argc, char **argv)
// {
// 	char	dest[20];
// 	char	src[20];

// 	if (argc == 3)
// 	{
// 		strcpy(dest, argv[1]);
// 		strcpy(src, argv[2]);
// 		printf("ft_strcat: %s\n", ft_strcat(dest, src));
// 		strcpy(dest, argv[1]);
// 		strcpy(src, argv[2]);
// 		printf("strcat: %s\n", strcat(dest, src));
// 	}
// }