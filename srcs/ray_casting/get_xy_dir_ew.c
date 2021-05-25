#include "cub3D.h"

static void	get_xy_ew(t_dot_intersct prio_wall, t_text text, int *x, int *y)
{
	float	decimal;

	decimal = prio_wall.dot.y - (int)prio_wall.dot.y;
	if (prio_wall.cardinal == EAST)
		decimal = 1 - decimal;
	(*x) = text.width * decimal;
	(*y) = text.height * (1 - prio_wall.dot.z);
}

unsigned int	get_xy_dir_ew(t_vars *cub, t_dot_intersct prio_wall)
{
	int				x;
	int				y;
	unsigned int	pixel;

	x = 0;
	y = 0;
	pixel = 0;
	if (prio_wall.cardinal == 2)
	{
		get_xy_ew(prio_wall, cub->parsing.textures[2], &x, &y);
		pixel = get_pixel(cub->parsing.textures[2], x, y);
	}
	else if (prio_wall.cardinal == 3)
	{
		get_xy_ew(prio_wall, cub->parsing.textures[3], &x, &y);
		pixel = get_pixel(cub->parsing.textures[3], x, y);
	}
	return (pixel);
}