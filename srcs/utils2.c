#include "cub3D.h"

void	my_mlx_pixel_put(t_vars *mlx, int x, int y, unsigned int color)
{
	char	*dst;
	int		temp;

	temp = y * mlx->ray_c.line_length + x
			* (mlx->ray_c.bits_per_pixel * 0.125);
	dst = mlx->ray_c.addr + temp;
	*(unsigned int*)dst = color;
}

unsigned int	get_pixel(t_text texture, int x, int y)
{
	int	temp;

	if (!(x >= 0 && y >= 0 && x < texture.width && y < texture.height))
		return (0);
	temp =  y * (texture.line_length * 0.25) + x;
	return (texture.addr[temp]);
}