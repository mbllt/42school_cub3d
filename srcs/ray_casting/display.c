#include "cub3D.h"

static void	save_display(t_vars *cub, unsigned int pixel, int *i, int *j)
{
	(*i) *= 2;
	(*j) *= 2;
	my_mlx_pixel_put(cub, (*i) + 1, (*j) + 1, (unsigned int)pixel);
	my_mlx_pixel_put(cub, (*i), (*j) + 1, (unsigned int)pixel);
	my_mlx_pixel_put(cub, (*i) + 1, (*j), (unsigned int)pixel);
}

void	display(t_vars *cub, t_index index, t_dot_intersct prio_wall, float r)
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
	//if (prio_wall.t_distance > 1)
	pixel = dark_color(pixel, prio_wall.t_distance);
	// if (prio_wall.cardinal == EAST && prio_wall.t_distance >= 3.0)
	// 	printf("%x\n", pixel);
	// printf("%d\n", pixel);
	if (cub->save_on == 1)
		cub->pixel_data[index.x][index.y] = pixel;
	if (cub->parsing.scale_on == 1)
		save_display(cub, pixel, &index.x, &index.y);
	my_mlx_pixel_put(cub, index.x, index.y, (unsigned int)pixel);
}
