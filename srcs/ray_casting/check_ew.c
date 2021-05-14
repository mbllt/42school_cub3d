#include "cub3D.h"

static void	intersct_dot(t_vars *cub, t_vector ray)
{
	cub->ray_c.xyz.x = cub->parsing.px + (ray.x * cub->ray_c.distance);
	cub->ray_c.xyz.y = cub->parsing.py + (ray.y * cub->ray_c.distance);
	cub->ray_c.xyz.z = cub->parsing.pz + (ray.z * cub->ray_c.distance);
}

static int	intersct_plan_ew(t_vars *cub, t_vector ray, t_plan plan)
{
	float	diviseur;

	diviseur = (plan.a * ray.x) + (plan.b * ray.y);
	if (diviseur == 0)
		return (0);
	cub->ray_c.distance = - ((plan.a * cub->parsing.px) + (plan.b * cub->parsing.py) + plan.d);
	cub->ray_c.distance /= diviseur;
	if (plan.d == 2)
	{
		//printf("%f\n", cub->parsing);
	}
	if (cub->ray_c.distance < 0)
		return (0);
	intersct_dot(cub, ray);
	return (1);
}

t_dot_intersct	check_wall_e(t_vars *cub, t_vector ray)
{
	int	i;

	i = (int)cub->parsing.px;
	i = 1;
	while (i < cub->parsing.map_y)
	{
		//printf("yppy\n");
		if ((intersct_plan_ew(cub, ray, cub->ray_c.plans[2])) == 1)
		{
			//printf("yppy\n");
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 2});
			else
			{
				//printf("%f\n", cub->ray_c.xyz.z);
				return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
			}
		}
		i++;
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}

t_dot_intersct	check_wall_w(t_vars *cub, t_vector ray)
{
	int	i;

	i = (int)cub->parsing.px;
	i = 0;
	while (i >= 0)
	{
		if ((intersct_plan_ew(cub, ray, cub->ray_c.plans[3])) == 1)
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

// t_dot_intersct	check_wall_e(t_vars *cub, t_vector ray)
// {
// 	int	i;

// 	i = (int)cub->parsing.px - 1;
// 	i = 1;
// 	while (i <= cub->parsing.map_y)
// 	{
// 		if (!(intersct_plan_ew(cub, ray, cub->ray_c.plans[i])))
// 		{
// 			if (cub->ray_c.xyz.z >= 0 && cub->ray_c.xyz.z < 1)
// 			{
// 				if (cub->parsing.world_map[(int)cub->ray_c.xyz.x] \
// 					[(int)cub->ray_c.xyz.y] == '1') \
// 							return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 2});
// 				else
// 					return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
// 			}
// 		}
// 		i++;
// 	}
// 	return ((t_dot_intersct){(t_vector){0,0,0}, 0, -1});
// }

// t_dot_intersct	check_wall_w(t_vars *cub, t_vector ray)
// {
// 	int	i;

// 	i = (int)cub->parsing.px + 1;
// 	i = 0;
// 	while (i >= 0)
// 	{
// 		if (!(intersct_plan_ew(cub, ray, cub->ray_c.plans[i])))
// 		{
// 			if (cub->ray_c.xyz.z >= 0 && cub->ray_c.xyz.z < 1)
// 			{
// 				if (cub->parsing.world_map[(int)cub->ray_c.xyz.x] \
// 					[(int)cub->ray_c.xyz.y] == '1')
// 							return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 3});
// 				else
// 					return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1});
// 			}
// 		i--;
// 		}
// 	}
// 	return ((t_dot_intersct){(t_vector){0,0,0}, 0, -1});
// }