/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:24:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/04/05 15:14:53 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == 0)
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && to_find[j] != '\0'
			&& str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (0);
}
// int main(void)
// {
// 	char str1[] = "Hello, this is a test string!";
// 	char to_find1[] = "test";
// 	char to_find2[] = "world";
// 	char to_find3[] = "";
// 	char *result;

// 	result = ft_strstr(str1, to_find1);
// 	printf("Haystack: %s, Needle: %s\nResult: %s\n", str1, to_find1, result);
// 	result = ft_strstr(str1, to_find2);
// 	printf("Haystack: %s,Needle: %s\nResult: %s\n", str1, to_find2, result);
// 	result = ft_strstr(str1, to_find3);
// 	printf("Haystack: %s, Needle: %s\nResult: %s\n", str1, to_find3, result);
// }