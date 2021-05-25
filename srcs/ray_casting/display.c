#include "cub3D.h"

static void	save_display(t_vars *cub, unsigned int pixel, int *i, int *j)
{
	(*i) *= 2;
	(*j) *= 2;
	my_mlx_pixel_put(cub, (*i) + 1, (*j) + 1, (unsigned int)pixel);
	my_mlx_pixel_put(cub, (*i), (*j) + 1, (unsigned int)pixel);
	my_mlx_pixel_put(cub, (*i) + 1, (*j), (unsigned int)pixel);
}

void	display(t_vars *cub, int i, int j, t_dot_intersct prio_wall, float r)
{
	int				x;
	int				y;
	unsigned int	pixel;

	x = 0;
	y = 0;
	pixel = 0;
	if (prio_wall.cardinal == NORTH || prio_wall.cardinal == SOUTH)
		pixel = get_xy_dir_ns(cub, prio_wall);
	if (prio_wall.cardinal == EAST || prio_wall.cardinal == WEST)
		pixel = get_xy_dir_ew(cub, prio_wall);
	if (prio_wall.cardinal == F || prio_wall.cardinal == C)
		pixel = get_xy_dir_fc(cub, prio_wall);
	if (prio_wall.cardinal == SPRITE)
		pixel = get_xy_spritee(cub, prio_wall, r);
	if (cub->save_on == 1)
		cub->pixel_data[i][j] = pixel;
	if (cub->parsing.scale_on == 1)
		save_display(cub, pixel, &i, &j);
	my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
}
