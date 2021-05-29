#include "cub3D.h"

static int	size_itoa(long int n)
{
	if (n < 0)
		return (1 + (size_itoa(n * -1)));
	else if (n >= 10)
		return (1 + (size_itoa(n / 10)));
	return (1);
}

static char	*fill_in_str(long int n, char *str, int size)
{
	str[size] = '\0';
	size--;
	if (n < 0 || n == -0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n == 0)
	{
		str[size] = n + 48;
	}
	while (n > 0)
	{
		str[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = size_itoa(n);
	str = NULL;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	fill_in_str((long int)n, str, size);
	return (str);
}
