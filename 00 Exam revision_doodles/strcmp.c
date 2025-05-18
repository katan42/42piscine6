
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{	
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		printf("ft_strcmp: %d\n", ft_strcmp(argv[1], argv[2]));
		printf("strcmp: %d\n", strcmp(argv[1], argv[2]));
	}
}