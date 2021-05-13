#include "cub3D.h"

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}t_dir;

void	intersct_dot(t_vars *cub, t_vector ray)
{
	cub->ray_c.xyz.x = cub->parsing.px + (ray.x * cub->ray_c.distance);
	cub->ray_c.xyz.y = cub->parsing.py + (ray.y * cub->ray_c.distance);
	cub->ray_c.xyz.z = cub->parsing.pz + (ray.z * cub->ray_c.distance);
}

int	intersct_plan(t_vars *cub, t_plan plan, t_vector ray)
{
	float	diviseur;

	diviseur = (plan.a * ray.x) + (plan.b * ray.y);
	if (diviseur == 0)
		return (0);
	cub->ray_c.distance = - ((plan.a * cub->parsing.px) \
							+ (plan.b * cub->parsing.py) + plan.d);
	cub->ray_c.distance /= diviseur;
	if (cub->ray_c.distance < 0)
		return (0);
	intersct_dot(cub, ray);
	return (1);
}

void	display(t_vars *cub, int i, int j, int orienta_wall)
{
	if (orienta_wall == NORTH)
	{
		//printf("%d\n", orienta_wall);
		my_mlx_pixel_put(cub, i, j, TEAL);
	}
	if (orienta_wall == SOUTH)
	{
		my_mlx_pixel_put(cub, i, j, PINK);
	}
	if (orienta_wall == EAST)
	{
		//printf("yoy\n");
		my_mlx_pixel_put(cub, i, j, BROWN);
	}
	if (orienta_wall == WEST)
		my_mlx_pixel_put(cub, i, j, ORANGE);
}