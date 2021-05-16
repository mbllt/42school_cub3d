#include "cub3D.h"

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	F,
	C,
}t_dir;

void	my_mlx_pixel_put(t_vars *mlx, int x, int y, uintptr_t color)
{
	int		temp;
	char	*dst;

	temp = y * mlx->ray_c.line_length + x * (mlx->ray_c.bits_per_pixel * 0.125);
	dst = mlx->ray_c.addr + temp;
	*(uintptr_t*)dst = color;
}

char	*get_pixel(t_text texture, int x, int y)
{
	int		temp;
	char	*dst;

	temp = (*texture.height - y - 1) * texture.line_length + x * (texture.bits_per_pixel * 0.125);
	dst = texture.addr + temp;
	return (dst);
}

void	display(t_vars *cub, int i, int j, int orienta_wall)
{
	int			k;
	uintptr_t	colors[7];

	colors[0] = TEAL;
	colors[1] = PINK;
	colors[2] = BROWN;
	colors[3] = ORANGE;
	colors[4] = GREEN;
	colors[5] = BLUE;
	colors[6] = GREY;
	k = -1;
	while (++k < 7)
	{
		if (orienta_wall == k)
		{
			my_mlx_pixel_put(cub, i, j, colors[k]);
		}
	}
	// if (orienta_wall == -1)
	// 	printf("%d\n", orienta_wall);
}



	// int	x;
	// int	y;
	// char *color;
	// int	k;

	// k = -1;
	// while (++k < 5)
	// {
	// 	if (orienta_wall == k)
	// 	{
	// 		color = get_pixel(cub->parsing.textures[k], x, y);
	// 		my_mlx_pixel_put(cub, i, j, color);
	// 	}
	// }