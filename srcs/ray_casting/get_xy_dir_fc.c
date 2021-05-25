#include "cub3D.h"

static void	get_xy_fc(t_dot_intersct prio_wall, t_text text, int *x, int *y)
{
	float	decimal;

	decimal = prio_wall.dot.x - (int)prio_wall.dot.x;
	(*x) = text.width * (1 - decimal);
	decimal = prio_wall.dot.y - (int)prio_wall.dot.y;
	(*y) = text.height * (1 - decimal);
}

unsigned int	get_xy_dir_fc(t_vars *cub, t_dot_intersct prio_wall)
{
	unsigned int	pixel;
	int				x;
	int				y;

	x = 0;
	y = 0;
	pixel = 0;
	if (prio_wall.cardinal == F)
	{
		get_xy_fc(prio_wall, cub->parsing.textures[4], &x, &y);
		pixel = get_pixel(cub->parsing.textures[4], x, y);
	}
	else if (prio_wall.cardinal == C)
	{
		get_xy_fc(prio_wall, cub->parsing.textures[5], &x, &y);
		pixel = get_pixel(cub->parsing.textures[5], x, y);
	}
	return (pixel);
}
