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

int	check_one(char c, char d, char e, char f)
{
	if (!(is_one(c)) || !(is_one(d)) || !(is_one(e)) || !(is_one(f)))
		return (0);
	return (1);
}

int	is_param_text(char c, char d, int ret)
{
	static int	all_param = 0;

	if (c == 'N')
		return (0);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (2);
	if (c == 'W')
		return (3);
	if (c == 'F')
		return (4);
	if (c == 'C')
		return (5);
	if (c == 'S')
		return (6);
	return (-1);
}
