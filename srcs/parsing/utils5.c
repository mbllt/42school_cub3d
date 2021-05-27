#include "cub3D.h"

int	is_color_path(char *str)
{
	char	c;
	int		i;

	c = ',';
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_double(char c)
{
	
}
