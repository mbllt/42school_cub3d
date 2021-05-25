#include "cub3D.h"

void	get_xy_sprite(t_dot_intersct prio_wall, t_text text, t_index *index, \
						float r)
{
	(*index).x = text.width * (1 - r);
	(*index).y = text.height * (1 - prio_wall.dot.z);
}

unsigned int	get_xy_spritee(t_vars *cub, t_dot_intersct prio_wall, float r)
{
	unsigned int	pixel;
	t_index			index;

	index.x = 0;
	index.y = 0;
	pixel = 0;
	get_xy_sprite(prio_wall, cub->parsing.textures[6], &index, r);
	pixel = get_pixel(cub->parsing.textures[6], index.x, index.y);
	return (pixel);
}
