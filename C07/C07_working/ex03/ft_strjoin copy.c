/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/09 20:04:12 by ka-tan           ###   ########.fr       */
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

char	*join_words(int size,char **strs, char *sep, int totlen)
{
	int		i;
	int		j;
	int		k;
	char	*str;	

	i = 0;
	j = 0;
	k = 0;
	str = malloc(totlen + 1);
	if (!str)
		return (NULL);
	while (i < size)
	{	
		j = 0;
		while (strs[i][j] != '\0')
			str[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j] != '\0')
				str[k++] = sep[j++]; 
		}
		i++;
	}
	str[k] = '\0';
	return(str);
}


char	*ft_strjoin(int size,char **strs, char *sep)
{
	char	*str;
	// int		i;
	// int		j;
	// int		k;
	int		totlen;

	// i = 0;
	// k = 0;
	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	totlen = total_len(size, strs, sep);
	str = join_words(size, strs, sep, totlen);
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