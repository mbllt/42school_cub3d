#include "cub3D.h"

static int	intersct_plan_ns(t_vars *cub, t_vector ray, int i)
{
	if (ray.y == 0)
		return (0);
	cub->ray_c.distance = - cub->parsing.py + i;
	cub->ray_c.distance /= ray.y;
	if (cub->ray_c.distance < 0)
		return (0);
	intersct_dot(cub, ray);
	return (1);
}

static int	is_wall_n(t_vars *cub, int x, int y)
{
	int	zero;

	if (x >= 0 && x < cub->parsing.map_x - 1 \
		&& y >= 0 && y < cub->parsing.map_y - 1 \
		&& cub->parsing.world_map[y][x] == '1')
	{
		zero = 0;
		while (y < cub->parsing.map_y - 1)
		{
			if (cub->parsing.world_map[y][x] != '1')
				zero++;
			y++;
		}
		if (zero != 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

t_dot_intersct	check_wall_n(t_vars *cub, t_vector ray)
{
	int	i;
	int	x;
	int	y;

	i = (int)cub->parsing.py;
	while(i >= 0)
	{
		if ((intersct_plan_ns(cub, ray, i)) == 1)
		{
			x = (int)cub->ray_c.xyz.x;
			y = i - 1;
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0 \
				&& (is_wall_n(cub, x, y)) == 1)
			{
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 0});
			}
			else if (cub->ray_c.xyz.z >= 1 || cub->ray_c.xyz.z < 0)
			{
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
			}
		}
		i--;
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}

static int	is_wall_s(t_vars *cub, int x, int y)
{
	int	zero;

	if (x >= 0 && x < cub->parsing.map_x \
		&& y >= 0 && y < cub->parsing.map_y \
		&& cub->parsing.world_map[y][x] == '1')
	{
		zero = 0;
		while (y >= 0)
		{
			if (cub->parsing.world_map[y][x] != '1')
				zero++;
			y--;
		}
		if (zero != 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

t_dot_intersct	check_wall_s(t_vars *cub, t_vector ray)
{
	int	i;
	int	x;
	int	y;

	i = (int)cub->parsing.py;
	while (i < cub->parsing.map_y)
	{
		if ((intersct_plan_ns(cub, ray, i)) == 1)
		{
			x = (int)cub->ray_c.xyz.x;
			y = i;
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0 \
				&& (is_wall_s(cub, x, y)) == 1)
			{
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 1});
			}
			else if (cub->ray_c.xyz.z >= 1 || cub->ray_c.xyz.z < 0)
			{
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
			}
		}
		i++;
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}
