#include "cub3D.h"

static int	ft_cpyy(char **dest, char *src, int size, int i)
{
	int	j;

	(*dest) = malloc(sizeof(char) * size + 1);
	if (!(*dest))
		return (0);
	j = 0;
	while (src[i])
	{
		(*dest)[j] = src[i];
		j++;
		i++;
	}
	(*dest)[j] = '\0';
	return (1);
}

static void	get_paths(t_vars *cub, char *str, int cardinal)
{
	int	size;
	int	i;

	i = 0;
	if (cardinal >= 0 && cardinal <= 3)
		i = 3;
	if (cardinal >= 4 && cardinal <= 6)
		i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	size = ft_strlen(str) - i;
	if (cardinal == NORTH)
		ft_cpyy(&cub->parsing.no, str, size, i);
	if (cardinal == SOUTH)
		ft_cpyy(&cub->parsing.so, str, size, i);
	if (cardinal == EAST)
		ft_cpyy(&cub->parsing.ea, str, size, i);
	if (cardinal == WEST)
		ft_cpyy(&cub->parsing.we, str, size, i);
	if (cardinal == 4)
		ft_cpyy(&cub->parsing.f, str, size, i);
	if (cardinal == 5)
		ft_cpyy(&cub->parsing.c, str, size, i);
	if (cardinal == 6)
		ft_cpyy(&cub->parsing.s, str, size, i);
}

static int	check_get_path(t_vars *cub, char *str, int cardinal)
{
	if (cardinal >= 0 && cardinal <= 3 && str[2] != ' ')
		return (0);
	if (cardinal >= 4 && cardinal <= 6 && str[1] != ' ')
		return (0);
	get_paths(cub, str, cardinal);
	return (1);
}

int	check_path_textures(t_vars *cub, char *line)
{
	int	cardinal;
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	cardinal = is_param_text(line[i]);
	if (cardinal == 4 && is_color_path(line) == 1)
		return (1);
	else if (cardinal == 4)
		cub->parsing.f_color_on = 0;
	if (cardinal == 5 && is_color_path(line) == 1)
		return (1);
	else if (cardinal == 5)
		cub->parsing.c_color_on = 0;
	if (cardinal == 1 && line[1] == ' ')
		cardinal = 6;
	if (!(check_get_path(cub, line, cardinal)))
	{
		write(1, "\nError : path textures\n", 23);
		return (0);
	}
	return (1);
}
