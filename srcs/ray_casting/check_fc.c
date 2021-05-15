#include "cub3D.h"

static int	intersct_plan_fc(t_vars *cub, t_vector ray, int i)
{
	if (ray.z == 0)
	{
		return (0);
	}
	cub->ray_c.distance = i - cub->parsing.pz;
	cub->ray_c.distance /= ray.z;
	if (cub->ray_c.distance < 0)
	{
		return (0);
	}
	intersct_dot(cub, ray);
	return (1);
}

t_dot_intersct	check_wall_f(t_vars *cub, t_vector ray)
{
	if ((intersct_plan_fc(cub, ray, 0)) == 1)
	{
		return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 4});
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}

t_dot_intersct	check_wall_c(t_vars *cub, t_vector ray)
{
	if ((intersct_plan_fc(cub, ray, 1)) == 1)
	{
		return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 5});
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}