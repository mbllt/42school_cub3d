#include "cub3D.h"

#define KEYUP		126
#define KEYDOWN		125
#define KEYRIGHT	124
#define KEYLEFT		123
#define W			13
#define S			1
#define D			2
#define A			0

void	my_mlx_pixel_put(t_vars *mlx, int x, int y, uintptr_t color)
{
	char	*dst;

	dst = mlx->ray_c.addr + (y * mlx->ray_c.line_length + x
			* (mlx->ray_c.bits_per_pixel / 8));
	*(uintptr_t*)dst = color;
}

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
	exit(0);
	return (0);
}

int	key_press(int key, t_vars *cub)
{
	// if (time(NULL) == cub->seconde)
	// 	cub->fps++;
	// else
	// 	printf("fps : %d\n", cub->fps);
	if (key == W || key == KEYUP)
		cub->ray_c.key.up = 1;
	if (key == KEYDOWN || key == S)
		cub->ray_c.key.down = 1;
	if (key == D)
	{
		//printf("       HERE\n");
		cub->ray_c.key.right = 1;
	}
	if (key == A)
		cub->ray_c.key.left = 1;
	if (key == KEYLEFT)
		cub->ray_c.key.rot_left = 1;
	if (key == KEYRIGHT)
		cub->ray_c.key.rot_right = 1;
	if (key == 53)
		cub->ray_c.key.exit = 1;
	//printf("%d\n", key);
	// if (!(browse_rays(cub, cub->parsing.rx, cub->parsing.ry)))
	// 	return (0);
	return (1);
}

int	key_release(int key, t_vars *cub)
{
	// if (time(NULL) == cub->seconde)
	// 	cub->fps++;
	// else
	// 	printf("fps : %d\n", cub->fps);
	if (key == W || key == KEYUP)
		cub->ray_c.key.up = 0;
	if (key == KEYDOWN || key == S)
		cub->ray_c.key.down = 0;
	if (key == D)
		cub->ray_c.key.right = 0;
	if (key == A)
		cub->ray_c.key.left = 0;
	if (key == KEYLEFT)
	{
		cub->ray_c.key.rot_left = 0;
		cub->ray_c.rota = 0;
	}
	if (key == KEYRIGHT)
	{
		cub->ray_c.key.rot_right = 0;
		cub->ray_c.rota = 0;
	}
	// if (!(browse_rays(cub, cub->parsing.rx, cub->parsing.ry)))
	// 	return (0);
	return (1);
}
