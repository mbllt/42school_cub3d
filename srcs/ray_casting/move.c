#include "cub3D.h"

void	move(t_vars *cub, t_vector *ray, t_vector *ray_temp)
{
	(*ray_temp) = rotation_x(cub, (*ray));
	(*ray_temp) = rotation_z(cub, (*ray_temp));
	if (cub->ray_c.key.right == 1)
	{
		cub->parsing.px -= (*ray).y * 0.07;
		cub->parsing.py += (*ray).x * 0.07;
	}
}