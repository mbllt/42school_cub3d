#include "cub3D.h"

static void	intersct_dot(t_vars *cub, t_vector ray)
{
	cub->ray_c.xyz.x = cub->parsing.px + (ray.x * cub->ray_c.distance);
	cub->ray_c.xyz.y = cub->parsing.py + (ray.y * cub->ray_c.distance);
	cub->ray_c.xyz.z = cub->parsing.pz + (ray.z * cub->ray_c.distance);
}

static int	intersct_plan_fc(t_vars *cub, t_vector ray, t_plan plan)
{
	float	diviseur;

	diviseur = (plan.c * ray.z);
	if (diviseur == 0)
	{
		return (0);
	}
	cub->ray_c.distance = - ((plan.c * cub->parsing.pz) + plan.d);
	cub->ray_c.distance /= diviseur;
	if (cub->ray_c.distance < 0)
	{
		return (0);
	}
	intersct_dot(cub, ray);
	return (1);
}

t_dot_intersct	check_wall_f(t_vars *cub, t_vector ray)
{
	if ((intersct_plan_fc(cub, ray, cub->ray_c.plans[4][0])) == 1)
	{
		return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 4});
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}

t_dot_intersct	check_wall_c(t_vars *cub, t_vector ray)
{
	if ((intersct_plan_fc(cub, ray, cub->ray_c.plans[5][0])) == 1)
	{
		return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 5});
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1});
}