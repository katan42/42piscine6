/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 00:56:19 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_slen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*str_cpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	unsigned int	i;	
	char			*dest;

	i = ft_slen(src);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!(dest))
	{
		return (0);
	}
	return (str_cpy (dest, src));
}

int		main(void)
{
		char	*str;
		char	*allocated;

		str = "Hello World with malloc()";
		printf("original  : base  : $%s$ @ %p\n", str, str);
		allocated = ft_strdup(str);
		printf("copied    : alloc : $%s$ @ %p\n", allocated, allocated);
		allocated = ft_strdup(str);
		printf("ft_copied : alloc : $%s$ @ %p\n", allocated, allocated);
}

