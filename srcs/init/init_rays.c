#include "cub3D.h"

void	init_rays(t_vars *cub, int width, int height, t_ray *ray_c)
{
	int	i;
	int	j;

	(void)cub;
	ray_c->fov = 60.0 * (M_PI / 180.0);
	ray_c->ratio_h = 2.0 * tan(ray_c->fov * 0.5) / width;
	ray_c->ratio_v = 2.0 * tan(ray_c->fov * height / \
		(width * 2.0)) / height;
	if (ray_c->ratio_v < 0)
		ray_c->ratio_v *= -1;
	if (ray_c->ratio_v * height > 2.4)
		write(1, "\nCarful, the view will not be realistic!\n", 42);
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
		{
			ray_c->stock_rays[i][j].x = (i - width * 0.5) * ray_c->ratio_h;
			ray_c->stock_rays[i][j].y = -1;
			ray_c->stock_rays[i][j].z = (height * 0.5 - j) * ray_c->ratio_v;
			ray_c->stock_rays[i][j] = normalisation_v(ray_c->stock_rays[i][j]);
		}
	}
}
