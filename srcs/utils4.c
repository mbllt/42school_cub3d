#include "cub3D.h"

void	change_ray_dir(t_vars *cub, char c)
{
	float	temp;

	temp = cub->ray_c.rota_z;
	if (c == 'S')
	{
		cub->ray_c.rota_z = M_PI;
		init_matrix_z(cub);
	}
	if (c == 'E')
	{
		cub->ray_c.rota_z = M_PI * 0.5;
		init_matrix_z(cub);
	}
	if (c == 'W')
	{
		cub->ray_c.rota_z = M_PI * 1.5;
		init_matrix_z(cub);
	}
}

void	my_mlx_pixel_put_bis(t_text text, int x, int y, unsigned int color)
{
	char	*dst;
	int		temp;

	temp = y * text.line_length + x * (text.bits_per_pixel * 0.125);
	dst = (char *)text.addr + temp;
	*(unsigned int *)dst = color;
}

void	ft_destroy(t_vars *cub)
{
	if (mlx_destroy_image(cub->ray_c.mlx, cub->ray_c.img))
		write(1, "\nDestroy image did not work\n", 27);
	if (mlx_destroy_window(cub->ray_c.mlx, cub->ray_c.win))
		write(1, "\nDestroy window did not work\n", 28);
}
