/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 20:34:43 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	totlen;

	i = 0;
	totlen = 0;
	while (i < size)
	{
		totlen = totlen + ft_strlen(strs[i]);
		i++;
	}
	totlen = totlen + (ft_strlen(sep) * (size - 1));
	return (totlen);
}

int	ft_strcpy_to(char *dest, char *src, int k)
{
	int	j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[k] = src[j];
		k++;
		j++;
	}
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		k;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		return ((str[0] = '\0'), str);
	}
	str = (char *)malloc(sizeof(char) * ((total_len(size, strs, sep)) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		k = ft_strcpy_to(str, strs[i], k);
		if (i < size - 1)
			k = ft_strcpy_to(str, sep, k);
		i++;
	}
	str[k] = '\0';
	return (str);
}

// int main(void)
// {
// 	char *words[] = {"Hello", "42", "world", "!"};
// 	char *separator = " ~ ";
// 	char *joined;

// 	joined = ft_strjoin(4, words, separator);
// 	if (joined)
// 	{
// 		printf("Joined string: \"%s\"\n", joined);
// 		free(joined);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}

// 	// Test for size == 0
// 	joined = ft_strjoin(0, words, separator);
// 	if (joined)
// 	{
// 		printf("Empty join: \"%s\"\n", joined);
// 		free(joined);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed (empty case).\n");
// 	}

// 	return 0;
// }