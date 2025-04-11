
// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	word_count(char *str)
{
	int	count = 0;
	int in_word_flag = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if(!is_space(str[i] && in_word_flag == 0))
		{
			in_word_flag = 1;
			count++;
		}
		else if (is_space(str[i]))
			in_word_flag = 0;
		i++;
	}
	return (count);
}

char	*word_dup(char *start, int len)
{
	char *word;
	int	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';

	return (word);
}

char **ft_split(char *str)
{
	char **result;
	int i = 0;
	int j = 0;
	int len = 0;
	int word_no = word_count(str);

	result = (char **)malloc(sizeof(char *) * (word_no + 1));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		if(!is_space(str[i]))
		{
			len = 0;
			while (str[i+len] && !is_space(str[i + len]))
				len++;
			result[j++] = word_dup(str+i, len);
			i = i + len;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

int main()
{
	char **words = ft_split("Hello ni hao ma\njin bu jin zhang\tok bye");
	int i = 0;

	while(words[i] != NULL)
	{
		printf("Word %d: %s\n", i, words[i]);
		free(words[i]);
		
	}
	free(words);
	return (0);
}
