#include "cub3D.h"

void	init_vars_rays(t_vars *cub)
{
	cub->ray_c.rays.x = 0;
	cub->ray_c.rays.y = -1;
	cub->ray_c.rays.z = 0;
}

int	init_stock_rays(t_vars *cub, int width, int height)
{
	int	i;

	cub->ray_c.stock_rays = malloc(sizeof(t_vector *) * width);
	if (!cub->ray_c.stock_rays)
		return (0);
	i = -1;
	while (++i < width)
	{
		cub->ray_c.stock_rays[i] = malloc(sizeof(t_vector) * height);
		if (!cub->ray_c.stock_rays[i])
			return (0);
	}
	return (1);
}