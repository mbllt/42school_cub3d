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

int	check_double_nsews(char c, char d)
{
	static int	n = 0;
	static int	so = 0;
	static int	e = 0;
	static int	w = 0;
	static int	s = 0;

	if (c == 'N')
		n++;
	if (c == 'S' && d == 'O')
		so++;
	if (c == 'E')
		e++;
	if (c == 'W')
		w++;
	if (c == 'S' && d == ' ')
		s++;
	if (n > 1 || so > 1 || e > 1 || w > 1 || s > 1)
		return (0);
	return (1);
}

int	check_double_fc(char d)
{
	static int	f = 0;
	static int	c = 0;

	if (d == 'F')
		f++;
	if (d == 'C')
		c++;
	if (f > 1 || c > 1)
		return (0);
	return (1);
}
