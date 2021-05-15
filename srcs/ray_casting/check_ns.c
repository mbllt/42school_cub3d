#include "cub3D.h"

static int	intersct_plan_ns(t_vars *cub, t_vector ray, int i)
{
	if (ray.y == 0)
		return (0);
	cub->ray_c.distance = - cub->parsing.py + i;
	cub->ray_c.distance /= ray.y;
	if (cub->ray_c.distance < 0)
		return (0);
	//printf("%f\n", ray.z);
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

	i = (int)cub->parsing.py + 1;
	//i = 0;
	while(i >= 0)
	{
		if ((intersct_plan_ns(cub, ray, i)) == 1)
		{
			x = (int)cub->ray_c.xyz.x;
			y = i;
			//for (int m = 0;m < cub->parsing.map_x;m++)
				//printf("%s\n", cub->parsing.world_map[m]);
			// if (x >= 0 && x < cub->parsing.map_x -1 \
			// 	&& y >= 0 && y < cub->parsing.map_y -1)
			// 	printf("world_map[%d] :%s\n", x, cub->parsing.world_map[x]);
			//if (cub->parsing.world_map[3][1] == '1')
				//printf("x :%d && y :%d\n", x, y);
			// if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
			// 	printf("z :%f\n", cub->ray_c.xyz.z);
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0 \
				&& (is_wall_n(cub, x, y)) == 1)
				// && x >= 0 && x < cub->parsing.map_x - 1 \
				// && y >= 0 && y < cub->parsing.map_y - 1 \
				// && cub->parsing.world_map[y][x] == '1')
			{
				//printf("colonne nord :%d\n", y);
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
	//i = 1;
	while (i < cub->parsing.map_y)
	{
		if ((intersct_plan_ns(cub, ray, i)) == 1)
		{
			x = (int)cub->ray_c.xyz.x; /* not sure + 1 */
			y = i + 1;
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0 \
				&& (is_wall_s(cub, x, y)) == 1)
				// && x >= 0 && x < cub->parsing.map_x - 1 \
				// && y >= 0 && y < cub->parsing.map_y - 1 \
				// && cub->parsing.world_map[y][x] == '1')
			{
				//printf("colonne nord :%d\n", y);
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

// t_dot_intersct	check_wall_n(t_vars *cub, t_vector ray)
// {
// 	int	i;

// 	i = (int)cub->parsing.py + 1;
// 	i = 0;
// 	while (i >= 0)
// 	{
// 		if (!(intersct_plan_ns(cub, ray, cub->ray_c.plans[i])))
// 		{
// 			if (cub->ray_c.xyz.z >= 0 && cub->ray_c.xyz.z < 1)
// 			{
// 				if (cub->parsing.world_map[(int)cub->ray_c.xyz.x] \
// 					[(int)cub->ray_c.xyz.y] == '1')
// 							return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 0});
// 				else
// 					return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
// 			}
// 		}
// 		i--;
// 	}
// 	return ((t_dot_intersct){(t_vector){0,0,0}, 0, -1});
// }

// t_dot_intersct	check_wall_s(t_vars *cub, t_vector ray)
// {
// 	int	i;

// 	i = (int)cub->parsing.py - 1;
// 	i = 1;
// 	while (i <= cub->parsing.map_x)
// 	{
// 		if (!(intersct_plan_ns(cub, ray, cub->ray_c.plans[i])))
// 		{
// 			if (cub->ray_c.xyz.z >= 0 && cub->ray_c.xyz.z < 1)
// 			{
// 				if (cub->parsing.world_map[(int)cub->ray_c.xyz.x] \
// 					[(int)cub->ray_c.xyz.y] == '1')
// 							return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 1});
// 				else
// 					return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
// 			}
// 		}
// 		i++;
// 	}
// 	return ((t_dot_intersct){(t_vector){0,0,0}, 0, -1});
// }