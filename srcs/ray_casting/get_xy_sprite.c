#include "cub3D.h"

void	get_xy_sprite(t_dot_intersct prio_wall, t_text text, int *x, int *y, \
						float r)
{
	(*x) = text.width * (1 - r);
	(*y) = text.height * (1 - prio_wall.dot.z);
}

unsigned int	get_xy_spritee(t_vars *cub, t_dot_intersct prio_wall, float r)
{
	unsigned int	pixel;
	int				x;
	int				y;

	x = 0;
	y = 0;
	pixel = 0;
	get_xy_sprite(prio_wall, cub->parsing.textures[6], &x, &y, r);
	pixel = get_pixel(cub->parsing.textures[6], x, y);
	return (pixel);
}