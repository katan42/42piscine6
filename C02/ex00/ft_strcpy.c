/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:23:01 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/05 16:24:14 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	dest[30] = "guo zhe guang de xin";
// 	char	src[30] = "guo zhe xin de guang";

// 	printf("bef: %s\n %s\n", dest, src);
// 	ft_strcpy(dest, src);
// 	printf("ft_strcpy: %s\n %s\n", dest, src);
// 	strcpy(dest, src);
// 	printf("strcpy: %s\n %s\n", dest, src);
// }