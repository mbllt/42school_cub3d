#include "cub3D.h"

int	size_colors(int nbr)
{
	if (nbr >= 0 && nbr <= 255)
		return (1);
	return (0);
}

int	is_param(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'R' || c == 'F' \
		|| c == 'C')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	long unsigned int	res;
	int					neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	if (str[i] == '+' && neg == 1)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
		if (str[i] < 48 || str[i] > 57)
			return (res * neg);
	}
	return (0);
}

char	*ft_realloc(char *str, size_t size)
{
	char	*str2;
	int		i;
	
	if (!str)
		return (NULL);
	if (!(str2 = malloc(sizeof(char) * size)))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (size > 0 && str[i] != '\0')
	{
		str2[i] = str[i];
		size--;
		i++;
	}
	str2[i] = 0;
	free(str);
	return (str2);
}

int	get_number( char *line, int *i, int nbr)
{
	int		j;
	char	*str;

	str =  NULL;
	j = 2;
	while (line[(*i)] >= 48 && line[(*i)] <= 57)
	{
		if (!str)
			str = malloc(sizeof(char) * j);
		else
			str = ft_realloc(str, j + 1);
		if (!str)
				return (0);
		str[j] = line[(*i)];
		str[j + 1] = 0;
		(*i)++;
		j++;
	}
	if (ft_strlen(str) > 9)
		str[8] = 0;
	nbr = ft_atoi(str);
	free(str);
	return (1);
}