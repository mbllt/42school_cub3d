#include "cub3D.h"

static void	get_size_y_map(t_vars *cub, char **map, int file_y)
{
	int	i;
	int	map_y;

	map_y = 0;
	while (--file_y)
	{
		i = 0;
		if (map[file_y][i] == ' ')
			i++;
		if (map[file_y][i] == '1')
			map_y++;
		else
			break;
	}
	cub->parsing.map_y = map_y;
}

static void	get_size_x_map(t_vars *cub, char **map, int file_y)
{
	int	i;
	int	map_x;

	map_x = 0;
	while (--file_y)
	{
		i = 0;
		if (map[file_y][i] == ' ')
			i++;
		if (map[file_y][i] == '1')
		{
			while (map[file_y][i])
				i++;
			if (i > map_x)
				map_x = i;
		}
		else
			break;
	}
	cub->parsing.map_x = map_x;
}

static int	get_cardinal(t_vars *cub)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < cub->parsing.map_y)
	{
		j = 0;
		while (j < cub->parsing.map_x)
		{
			if ((is_cardinal(cub->parsing.world_map[i][j])) >= 0)
			{
				cub->parsing.cardinal = cub->parsing.world_map[i][j];
				cub->parsing.py = i;
				cub->parsing.px = j;
				k++;
			}
			j++;
		}
		i++;
	}
	if (k != 1)
	{
		write(1, "\nNumber of cardinal is invalid\n", 31);
		return (0);
	}
	return (1);
}

int	ft_map(t_vars *cub, char **map, int file_y)
{
	get_size_y_map(cub, map, file_y);
	get_size_x_map(cub, map, file_y);
	if (!(get_world_map(cub, map, cub->parsing.map_y, file_y - 1)))
		return (0);
	if (!(check_world_map(cub, cub->parsing.world_map)))
		return (0);
	if (!(get_cardinal(cub)))
		return (0);
	return (1);
}