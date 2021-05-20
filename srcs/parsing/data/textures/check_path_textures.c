#include "cub3D.h"

// typedef enum e_cardinal
// {
// 	NORTH,
// 	SOUTH,
// 	EAST,
// 	WEST,
// 	SPRITE,
// }t_cardinal;

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

static void	get_path(t_vars *cub, char *str, int cardinal)
{
	int	size;
	int	i;

	i = 0;
	if (cardinal >= 0 && cardinal <= 3)
		i = 3;
	if (cardinal == 4)
		i = 2;
	while(str[i] && str[i] == ' ')
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
		ft_cpyy(&cub->parsing.s, str, size, i);
}

static int	check_get_path(t_vars *cub, char *str, int cardinal)
{
	if (cardinal >= 0 && cardinal <= 3 && str[2] != ' ')
		return (0);
	if (cardinal == 4 && str[1] != ' ')
		return (0);
	get_path(cub, str, cardinal);
	return (1);
}

int	check_path_textures(t_vars *cub, char *line)
{
	int	cardinal;
	int	i;

	i = 0;
	while(line[i] && line[i] == ' ')
		i++;
	cardinal = is_cardinal(line[i]);
	if (cardinal == 1 && line[1] == ' ')
		cardinal = 4;
	if (!(check_get_path(cub, line, cardinal)))
	{
		write(1, "\nError : path textures\n", 23);
		return (0);
	}
	return (1);
}