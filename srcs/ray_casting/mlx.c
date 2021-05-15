#include "cub3D.h"

#define KEYUP		126
#define KEYDOWN		125
#define KEYRIGHT	124
#define KEYLEFT		123
#define W			13
#define S			1
#define D			2
#define A			0
#define O			31
#define L			37

void	my_mlx_pixel_put(t_vars *mlx, int x, int y, uintptr_t color)
{
	int		temp;
	char	*dst;

	temp = y * mlx->ray_c.line_length + x \
			* (mlx->ray_c.bits_per_pixel * 0.125);
	dst = mlx->ray_c.addr + temp;
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
	if (key == O)
		cub->ray_c.key.up = 1;
	if (key == L)
		cub->ray_c.key.down = 1;
	if (key == W)
		cub->ray_c.key.forward = 1;
	if (key == S)
		cub->ray_c.key.backward = 1;
	if (key == D)
	{
		//printf("       HERE\n");
		cub->ray_c.key.right = 1;
	}
	if (key == A)
		cub->ray_c.key.left = 1;
	if (key == KEYUP)
		cub->ray_c.key.rot_x_left = 1;
	if (key == KEYDOWN)
		cub->ray_c.key.rot_x_right = 1;
	if (key == KEYLEFT)
	{
		//printf("HERE\n");
		cub->ray_c.key.rot_z_left = 1;
	}
	if (key == KEYRIGHT)
		cub->ray_c.key.rot_z_right = 1;
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
	if (key == O)
		cub->ray_c.key.up = 0;
	if (key == L)
		cub->ray_c.key.down = 0;
	if (key == W)
		cub->ray_c.key.forward = 0;
	if (key == S)
		cub->ray_c.key.backward = 0;
	if (key == D)
		cub->ray_c.key.right = 0;
	if (key == A)
		cub->ray_c.key.left = 0;
	if (key == KEYLEFT)
	{
		cub->ray_c.key.rot_z_left = 0;
		//cub->ray_c.rota_z = 0;
	}
	if (key == KEYRIGHT)
	{
		cub->ray_c.key.rot_z_right = 0;
		//cub->ray_c.rota_z = 0;
	}
	if (key == KEYUP)
	{
		cub->ray_c.key.rot_x_left = 0;
		//cub->ray_c.rota_x = 0;
	}
	if (key == KEYDOWN)
	{
		cub->ray_c.key.rot_x_right = 0;
		//cub->ray_c.rota_x = 0;
	}
	// if (!(browse_rays(cub, cub->parsing.rx, cub->parsing.ry)))
	// 	return (0);
	return (1);
}
