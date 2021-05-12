#include "cub3D.h"

int	frame(t_vars *cub)
{
	// if (time(NULL) == cub->seconde)
	// 	cub->fps++;
	// else
	// 	printf("fps : %d\n", cub->fps);
	if (cub->ray_c.key.right == 1)
		cub->parsing.px += 0.07;
	if (cub->ray_c.key.left == 1)
		cub->parsing.px -= 0.07;
	if (cub->ray_c.key.down == 1)
		cub->parsing.py += 0.07;
	if (cub->ray_c.key.up == 1)
		cub->parsing.py -= 0.07;
	if (cub->ray_c.key.rot_right == 1)
	{
		cub->ray_c.rota = 0.03;
		init_matrix(cub);
	}
	if (cub->ray_c.key.rot_left == 1)
	{
		cub->ray_c.rota = -0.03;
		init_matrix(cub);
	}
	if (cub->ray_c.key.exit == 1)
	{
		ft_exit(cub);
		return (0);
	}
	if (!(browse_rays(cub, cub->parsing.rx, cub->parsing.ry)))
		return (-1);
	mlx_put_image_to_window(cub->ray_c.mlx, cub->ray_c.win, cub->ray_c.img, 0, 0);
	return (1);
}