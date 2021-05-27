#include "cub3D.h"

static int	check_color(t_vars *cub, char **str, int size)
{
	if (!(check_colors(cub, str, size)))
	{
		write(1, "\nError : colors\n", 16);
		if (str)
			ft_double_free(str, size);
		return (0);
	}
	return (1);
}

static int	check_res(t_vars *cub, char **str, int size)
{
	if (!(check_get_res(cub, str, size)))
	{
		write(1, "\nError : resolution\n", 21);
		if (str)
			ft_double_free(str, size);
		return (0);
	}
	return (1);
}

int	check_res_color(t_vars *cub, char *line)
{
	int		size;
	char	**str;

	str = NULL;
	size = 0;
	str = ft_split(line, ' ', &size);
	if (!str)
		return (0);
	if (str[0][0] == 'R')
		if (!(check_res(cub, str, size)))
			return (0);
	if ((str[0][0] == 'C' || str[0][0] == 'F') && is_color_path(line) == 1)
		if (!(check_color(cub, str, size)))
			return (0);
	if (str)
		ft_double_free(str, size);
	return (1);
}
