#include "cub3D.h"

// typedef enum e_dir
// {
// 	NORTH,
// 	SOUTH,
// 	EAST,
// 	WEST,
// 	F,
// 	C,
// }t_dir;

void	my_mlx_pixel_put(t_vars *mlx, int x, int y, unsigned int color)
{
	char	*dst;
	int		temp;

	temp = y * mlx->ray_c.line_length + x
			* (mlx->ray_c.bits_per_pixel * 0.125);
	dst = mlx->ray_c.addr + temp;
	*(unsigned int*)dst = color;
}

static unsigned int	get_pixel(t_text texture, int x, int y)
{
	int	temp;

	if (!(x >= 0 && y >= 0 && x < texture.width && y < texture.height))
		return (0);
	temp =  y * (texture.line_length * 0.25) + x;
	return (texture.addr[temp]);
}

static void	get_xy_noso(t_dot_intersct prio_wall, t_text text, int *x, int *y)
{
	float	decimal;

	decimal = prio_wall.dot.x - (int)prio_wall.dot.x;
	if (prio_wall.cardinal == SOUTH)
		decimal = 1 - decimal;
	(*x) = text.width * decimal;
	(*y) = text.height * (1 - prio_wall.dot.z);
}

static void	get_xy_eawe(t_dot_intersct prio_wall, t_text text, int *x, int *y)
{
	float	decimal;

	decimal = prio_wall.dot.y - (int)prio_wall.dot.y;
	if (prio_wall.cardinal == EAST)
		decimal = 1 - decimal;
	(*x) = text.width * decimal;
	(*y) = text.height * (1 - prio_wall.dot.z);
}

void	display(t_vars *cub, int i, int j, t_dot_intersct prio_wall)
{
	int				x;
	int				y;
	unsigned int	pixel;

	x = 0;
	y = 0;
	if (prio_wall.cardinal == NORTH)
	{
		get_xy_noso(prio_wall, cub->parsing.textures[0], &x, &y);
		pixel = get_pixel(cub->parsing.textures[0], x, y);
		my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
	}
	else if (prio_wall.cardinal == SOUTH)
	{
		get_xy_noso(prio_wall, cub->parsing.textures[1], &x, &y);
		pixel = get_pixel(cub->parsing.textures[1], x, y);
		my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
	}
	else if (prio_wall.cardinal == EAST)
	{
		get_xy_eawe(prio_wall, cub->parsing.textures[2], &x, &y);
		pixel = get_pixel(cub->parsing.textures[2], x, y);
		my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
	}
	else if (prio_wall.cardinal == WEST)
	{
		get_xy_eawe(prio_wall, cub->parsing.textures[3], &x, &y);
		pixel = get_pixel(cub->parsing.textures[3], x, y);
		my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
	}
	else if (prio_wall.cardinal == F)
		my_mlx_pixel_put(cub, i, j, cub->parsing.ff);
	else if (prio_wall.cardinal == C)
		my_mlx_pixel_put(cub, i, j, cub->parsing.cc);
	else
	{
		// printf("%d, %d\n", i, j);
		my_mlx_pixel_put(cub, i, j, (unsigned int)"255,255,255");
	}
}