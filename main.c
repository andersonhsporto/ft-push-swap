#include <stdio.h>
#include "./libft/libft.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	str_isdigit(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (ft_isspace(string[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%d\n", ft_atoi("-22"));
	return (0);
}
