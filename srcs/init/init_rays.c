#include "cub3D.h"

void	init_rays(t_vars *cub, int width, int height)
{
	int	i;
	int	j;

	cub->ray_c.fov = 60.0 * (M_PI/180.0);
	cub->ray_c.ratio_horizon = 2.0 * tan(cub->ray_c.fov * 0.5)/width;
	cub->ray_c.ratio_vertical = 2.0 * tan(cub->ray_c.fov * height/(width * 2.0))/height;
	i  = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			cub->ray_c.stock_rays[i][j].x = ((float)i - width * 0.5) * cub->ray_c.ratio_horizon;
			cub->ray_c.stock_rays[i][j].y = -1;
			cub->ray_c.stock_rays[i][j].z = (height * 0.5 - (float)j) * cub->ray_c.ratio_vertical;
			// cub->ray_c.rota = 3.1;
			// init_matrix(cub);
			// rotation(cub, &cub->ray_c.stock_rays[i][j]);
			j++;
		}
		i++;
	}
}
