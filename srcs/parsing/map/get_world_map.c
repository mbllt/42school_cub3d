#include "cub3D.h"

static size_t	ft_cpymap(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	if (!src || !dest)
		return (0);
	j = ft_strlen(src);
	if (destsize == 0)
		return (j);
	i = 0;
	while (src[i] && i < j)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < destsize)
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
	return (j);
}

int	get_world_map(t_vars *cub, char **map, int map_y, int file_y)
{
	int	i;
	int	index_map;

	cub->parsing.world_map = malloc(sizeof(char *) * map_y);
	if (!cub->parsing.world_map)
		return (0);
	i = 0;
	while (i < map_y)
	{
		cub->parsing.world_map[i] = malloc(sizeof(char) \
			* (cub->parsing.map_x + 1));
		if (!cub->parsing.world_map[i])
		{
			ft_double_free(cub->parsing.world_map, i);
			return (0);
		}
		index_map = (file_y - (map_y - 1)) + i;
		if (cub->parsing.zero != 0)
			index_map -= cub->parsing.zero;
		if (!(ft_cpymap(cub->parsing.world_map[i], map[index_map], \
				cub->parsing.map_x)))
			return (0);
		i++;
	}
	return (1);
}
