#include "cub3D.h"

int	frame(t_vars *cub)
{
	//printf("%d\n", cub->ray_c.key.right);
	if (cub->ray_c.key.right == 1)
	{
		//printf("right            HERE\n");
		cub->parsing.px += 0.07;
	}
	if (cub->ray_c.key.left == 1)
	{
		//printf("left            HERE\n");
		cub->parsing.px -= 0.07;
	}
	if (cub->ray_c.key.down == 1)
	{
		//printf("down            HERE\n");
		cub->parsing.py += 0.07;
	}
	if (cub->ray_c.key.up == 1)
	{
		//printf("up            HERE\n");
		cub->parsing.py -= 0.07;
	}
	if (cub->ray_c.key.rot_right == 1)
	{
		//printf("rot right            HERE\n");
		cub->ray_c.rota = 0.03;
		init_matrix(cub);
	}
	if (cub->ray_c.key.rot_left == 1)
	{
		//printf("rot left            HERE\n");
		cub->ray_c.rota = -0.03;
		init_matrix(cub);
	}
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