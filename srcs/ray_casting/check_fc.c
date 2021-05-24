#include "cub3D.h"

static int	intersct_plan_fc(t_vars *cub, t_vector ray, int i, \
		t_dot_intersct *intersct)
{
	if (ray.z == 0)
	{
		return (0);
	}
	(*intersct).t_distance = i - cub->parsing.pz;
	(*intersct).t_distance /= ray.z;
	if ((*intersct).t_distance < 0)
	{
		return (0);
	}
	intersct_dot(cub, ray, intersct);
	return (1);
}

t_dot_intersct	check_wall_f(t_vars *cub, t_vector ray, \
		t_dot_intersct *intersct)
{
	if ((intersct_plan_fc(cub, ray, 0, intersct)) == 1)
	{
		return ((t_dot_intersct){(*intersct).dot, \
			(*intersct).t_distance, 4, ray});
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1, ray});
}

t_dot_intersct	check_wall_c(t_vars *cub, t_vector ray, \
	t_dot_intersct *intersct)
{
	if ((intersct_plan_fc(cub, ray, 1, intersct)) == 1)
	{
		return ((t_dot_intersct){(*intersct).dot, \
			(*intersct).t_distance, 5, ray});
	}
	return ((t_dot_intersct){(t_vector){0, 0, 0}, -1, -1, ray});
}
