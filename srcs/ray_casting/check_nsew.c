#include "cub3D.h"

t_dot_intersct	check_wall_N(t_vars *cub, t_vector ray)
{
	int	i;

	i = (int)cub->parsing.py;
	i = 0;
	while(i >= 0)
	{
		if ((intersct_plan(cub, cub->ray_c.plans_n[i], ray)))
		{
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 0});
			else
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
		}
		i--;
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}

t_dot_intersct	check_wall_S(t_vars *cub, t_vector ray)
{
	int	i;

	i = (int)cub->parsing.py;
	i = 1;
	while (i < cub->parsing.map_x)
	{
		if ((intersct_plan(cub, cub->ray_c.plans_s[i], ray)))
		{
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 1});
			else
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
		}
		i++;
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}

t_dot_intersct	check_wall_E(t_vars *cub, t_vector ray)
{
	int	i;

	i = (int)cub->parsing.px;
	i = 1;
	while (i < cub->parsing.map_y)
	{
		if ((intersct_plan(cub, cub->ray_c.plans_e[i], ray)))
		{
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 2});
			else
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
		}
		i++;
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}

t_dot_intersct	check_wall_W(t_vars *cub, t_vector ray)
{
	int	i;

	i = (int)cub->parsing.px;
	i = 0;
	while (i >= 0)
	{
		if ((intersct_plan(cub, cub->ray_c.plans_w[i], ray)))
		{
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 3});
			else
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
		}
		i--;
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}