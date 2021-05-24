#include "cub3D.h"

static int	get_size_y_map(t_vars *cub, char **map, int file_y)
{
	int	i;
	int	map_y;
	int	size_file;

	size_file = file_y - 1;
	map_y = 0;
	while (--file_y)
	{
		i = 0;
		while (map[file_y][i] == ' ')
			i++;
		if (map[file_y][i])
			map_y++;
		else if (file_y == size_file && map[file_y][i] == 0)
			return (0);
		else
			break ;
	}
	cub->parsing.map_y = map_y;
	return (1);
}

static void	get_size_x_map(t_vars *cub, char **map, int file_y)
{
	int	i;
	int	map_x;

	map_x = 0;
	while (--file_y)
	{
		i = 0;
		while (map[file_y][i] == ' ')
			i++;
		if (map[file_y][i] == '1')
		{
			while (map[file_y][i])
				i++;
			if (i > map_x)
				map_x = i;
		}
		else
			break ;
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
				cub->parsing.px = j + 0.5;
				cub->parsing.py = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	if (k != 1)
		return (0);
	return (1);
}

int	ft_map(t_vars *cub, char **map, int file_y)
{
	if (!(get_size_y_map(cub, map, file_y)))
	{
		write(1, "\nError : map\n", 13);
		return (0);
	}
	get_size_x_map(cub, map, file_y);
	if (!(get_world_map(cub, map, cub->parsing.map_y, file_y - 1)))
	{
		return (0);
	}
	if (!(check_world_map(cub, cub->parsing.world_map)))
	{
		write(1, "\nError : map\n", 13);
		return (0);
	}
	if (!(get_cardinal(cub)))
	{
		write(1, "\nError : map\n", 13);
		return (0);
	}
	return (1);
}
