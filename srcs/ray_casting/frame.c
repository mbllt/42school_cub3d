#include "cub3D.h"

int	ft_exit(t_vars *cub)
{
	int	i;

	i = -1;
	mlx_destroy_window(cub->ray_c.mlx, cub->ray_c.win);
	while (++i < cub->parsing.rx)
	{
		if (cub->ray_c.stock_rays[i])
			free(cub->ray_c.stock_rays[i]);
	}
	if (cub->ray_c.stock_rays)
			free(cub->ray_c.stock_rays);
	i = -1;
	while (++i < 3)
	{
		if (cub->ray_c.matrix_z[i])
			free(cub->ray_c.matrix_z[i]);
	}
	free(cub->ray_c.matrix_z);
	//exit(0);
	return (0);
}

int	frame(t_vars *cub)
{
	// //cub->ray_c.seconde = time(NULL);
	// if (cub->ray_c.seconde == time(NULL))
	// 	cub->ray_c.fps++;
	// else
	// {
	// 	//printf("fps : %d\n", cub->ray_c.fps);
	// 	cub->ray_c.fps = 0;
	// }
	move(cub);
	rotate(cub);
	if (cub->ray_c.key.exit == 1)
	{
		ft_exit(cub);
		return (0);
	}
	//mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, cub->ray_c.win);
	//mlx_sync(MLX_SYNC_IMAGE_WRITABLE, cub->ray_c.mlx);
	if (!(browse_rays(cub, cub->parsing.rx, cub->parsing.ry)))
		return (-1);
	mlx_put_image_to_window(cub->ray_c.mlx, cub->ray_c.win, cub->ray_c.img, 0, 0);
	//mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, cub->ray_c.win);
	return (1);
}

