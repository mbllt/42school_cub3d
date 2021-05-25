#include "cub3D.h"

static void	get_xy_ns(t_dot_intersct prio_wall, t_text text, int *x, int *y)
{
	float	decimal;

	decimal = prio_wall.dot.x - (int)prio_wall.dot.x;
	if (prio_wall.cardinal == SOUTH)
		decimal = 1 - decimal;
	(*x) = text.width * decimal;
	(*y) = text.height * (1 - prio_wall.dot.z);
}

unsigned int	get_xy_dir_ns(t_vars *cub, t_dot_intersct prio_wall)
{
	unsigned int	pixel;
	int				x;
	int				y;

	x = 0;
	y = 0;
	pixel = 0;
	if (prio_wall.cardinal == 0)
	{
		get_xy_ns(prio_wall, cub->parsing.textures[0], &x, &y);
		pixel = get_pixel(cub->parsing.textures[0], x, y);
	}
	else if (prio_wall.cardinal == 1)
	{
		get_xy_ns(prio_wall, cub->parsing.textures[1], &x, &y);
		pixel = get_pixel(cub->parsing.textures[1], x, y);
	}
	return (pixel);
}
