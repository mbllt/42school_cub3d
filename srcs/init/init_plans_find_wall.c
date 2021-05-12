#include "cub3D.h"

typedef enum e_dirr
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}t_dirr;

static void	ft_bzero(void *s, size_t n)
{
	t_plan	*c;

	c = (t_plan *)s;
	while (n-- > 0)
		c[n] = (t_plan){0,0,0,0};
}


t_plan	*find_walls_n(t_vars *cub, int size, int cardinal)
{
	int		x;
	int		y;
	int		zero;
	t_plan	*str;

	str = malloc(sizeof(t_plan) * size);
	if (!str)
		return (0);
	ft_bzero(str, size);
	x = 0;
	while (x < cub->parsing.map_x)
	{
		zero = 0;
		y = cub->parsing.map_y;
		while (y > 0)
		{
			if (cub->parsing.world_map[y][x] == '0')
				zero++;
			if (cub->parsing.world_map[y][x] == '1' && zero != 0 && str[y].d == 0)
				str[y] = (t_plan){0,1,0,x};
			y--;
		}
		x++;
	}
	return (str);
}

t_plan	*find_walls_s(t_vars *cub, int size, int cardinal)
{
	int		x;
	int		y;
	int		zero;
	t_plan	*str;

	str = malloc(sizeof(t_plan) * size);
	if (!str)
		return (0);
	ft_bzero(str, size);
	x = 0;
	while (x < cub->parsing.map_x)
	{
		zero = 0;
		y = 0;
		while (y < cub->parsing.map_y)
		{
			if (cub->parsing.world_map[y][x] == '0')
				zero++;
			if (cub->parsing.world_map[y][x] == '1' && zero != 0 && str[y].d == 0)
				str[y] = (t_plan){0,1,0,x};
			y++;
		}
		x++;
	}
	return (str);
}

t_plan	*find_walls_e(t_vars *cub, int size, int cardinal)
{
	int		x;
	int		y;
	int		zero;
	t_plan	*str;

	str = malloc(sizeof(t_plan) * size);
	if (!str)
		return (0);
	ft_bzero(str, size);
	y = 0;
	while (y < cub->parsing.map_y)
	{
		zero = 0;
		x = 0;
		while (x < cub->parsing.map_x)
		{
			if (cub->parsing.world_map[x][y] == '0')
				zero++;
			if (cub->parsing.world_map[x][y] == '1' && zero != 0 && str[x].d == 0)
				str[x] = (t_plan){1,0,0,y};
			x++;
		}
		y++;
	}
	return (str);
}

t_plan	*find_walls_w(t_vars *cub, int size, int cardinal)
{
	int		x;
	int		y;
	int		zero;
	t_plan	*str;

	str = malloc(sizeof(t_plan) * size);
	if (!str)
		return (0);
	ft_bzero(str, size);
	y = 0;
	while (y < cub->parsing.map_y)
	{
		zero = 0;
		x = cub->parsing.map_x;
		while (x > 0)
		{
			if (cub->parsing.world_map[x][y] == '0')
				zero++;
			if (cub->parsing.world_map[x][y] == '1' && zero != 0 && str[x].d == 0)
				str[x] = (t_plan){1,0,0,y};
			x--;
		}
		y++;
	}
	return (str);
}