#include "cub3D.h"

static int	intersct_plan_ew(t_vars *cub, t_vector ray, int i)
{
	if (ray.x == 0)
		return (0);
	cub->ray_c.distance = i - cub->parsing.px;
	cub->ray_c.distance /= ray.x;
	if (cub->ray_c.distance < 0)
		return (0);
	intersct_dot(cub, ray);
	return (1);
}

static int	is_wall_e(t_vars *cub, int x, int y)
{
	int	zero;

	if (x >= 0 && x < cub->parsing.map_x \
		&& y >= 0 && y < cub->parsing.map_y \
		&& cub->parsing.world_map[y][x] == '1')
	{
		zero = 0;
		while (x >= 0)
		{
			if (cub->parsing.world_map[y][x] != '1')
				zero++;
			x--;
		}
		if (zero != 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

t_dot_intersct	check_wall_e(t_vars *cub, t_vector ray)
{
	int	i;
	int	x;
	int	y;

	i = (int)cub->parsing.px;
	while (i < cub->parsing.map_x)
	{
		if ((intersct_plan_ew(cub, ray, i)) == 1)
		{
			x = i;
			y = (int)cub->ray_c.xyz.y;
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0 \
				&& (is_wall_e(cub, x, y)) == 1)
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 2});
			else if (cub->ray_c.xyz.z >= 1 || cub->ray_c.xyz.z < 0)
			{
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
			}
		}
		i++;
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}

static int	is_wall_w(t_vars *cub, int x, int y)
{
	int	zero;

	if (x >= 0 && x < cub->parsing.map_x \
		&& y >= 0 && y < cub->parsing.map_y \
		&& cub->parsing.world_map[y][x] == '1')
	{
		zero = 0;
		while (x < cub->parsing.map_x - 1)
		{
			if (cub->parsing.world_map[y][x] != '1')
				zero++;
			x++;
		}
		if (zero != 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
t_dot_intersct	check_wall_w(t_vars *cub, t_vector ray)
{
	int	i;
	int	x;
	int	y;

	i = (int)cub->parsing.px;
	while (i >= 0)
	{
		if ((intersct_plan_ew(cub, ray, i)) == 1)
		{
			x = i - 1;
			y = (int)cub->ray_c.xyz.y;
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0 \
				&& (is_wall_w(cub, x, y)) == 1)
			{
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 3});
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
