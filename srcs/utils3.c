#include "cub3D.h"

# define FRONT		0
# define BACK		1
# define RIGHT		2
# define LEFT		3
# define MOVE_SPEED	0.09

int	malloc_sp_r_temp(t_vars *cub, t_dot_intersct **sprite, float **r_temp)
{
	(*sprite) = malloc(cub->ray_c.nbr_sprite * sizeof(t_dot_intersct));
	if (!(*sprite))
		return (0);
	(*r_temp) = malloc(cub->ray_c.nbr_sprite * sizeof(float));
	if (!(*r_temp))
		return (0);
	return (1);
}

void	free_sp_r_temp(t_dot_intersct **sprite, float **r_temp)
{
	if (*sprite)
		free(*sprite);
	if (*r_temp)
		free(*r_temp);
}

// inline unsigned int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

unsigned int	dark_color(unsigned int pixel, float distance)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = pixel >> 16;
	g = pixel << 16;
	g = g >> 24;
	b = pixel << 24;
	b = b >> 24;
	if ((r / (distance * 1.2)) <= r && (r / (distance * 1.2)) >= 0 \
		&& g / (distance * 1.2) <= g && (g / (distance * 1.2)) >= 0 \
		&& b / (distance * 1.2) <= b && (g / (distance * 1.2)) >= 0)
	{
		r /= distance * 1.2;
		g /= distance * 1.2;
		b /= distance * 1.2;
		return (r << 16 | g << 8 | b);
	}
	return (pixel);
}

void	rot_if_spon_sew(t_vars *cub, t_vector *ray)
{
	float	temp;

	temp = cub->ray_c.rota_z;
	if (cub->parsing.cardinal == 'S')
	{
		cub->ray_c.rota_z = 180.0 * (M_PI / 180.0);
		init_matrix_z(cub);
		*ray = rotation_z(cub, *ray);
	}
	cub->ray_c.rota_z = temp;
}

int	check_collision(t_vars *cub, t_vector temp_dir_ray, int key)
{
	t_vector	temp;
	
	if (key == FRONT)
	{
		temp.x = cub->parsing.px;
		temp.y = cub->parsing.py;
		temp.x += temp_dir_ray.x * MOVE_SPEED;
		temp.y += temp_dir_ray.y * MOVE_SPEED;
		if ((int)temp.x >= cub->parsing.map_x || (int)temp.x < 0 \
			|| (int)temp.y >= cub->parsing.map_y || (int)temp.y < 0 \
			|| cub->parsing.world_map[(int)temp.y][(int)temp.x] == '1' \
			/*&& is_cardinal(cub->parsing.world_map[(int)temp.x][(int)temp.y]) == -1*/)
			return (0);
	}
	else if (key == BACK)
	{
		temp.x = cub->parsing.px;
		temp.y = cub->parsing.py;
		temp.x -= temp_dir_ray.x * MOVE_SPEED;
		temp.y -= temp_dir_ray.y * MOVE_SPEED;
		if ((int)temp.x >= cub->parsing.map_x || (int)temp.x < 0 \
			|| (int)temp.y >= cub->parsing.map_y || (int)temp.y < 0 \
			|| cub->parsing.world_map[(int)temp.y][(int)temp.x] == '1' \
			/*&& is_cardinal(cub->parsing.world_map[(int)temp.x][(int)temp.y]) == -1*/)
			return (0);
	}
	if (key == RIGHT)
	{
		temp.x = cub->parsing.px;
		temp.y = cub->parsing.py;
		temp.x -= temp_dir_ray.y * MOVE_SPEED;
		temp.y += temp_dir_ray.x * MOVE_SPEED;
		if ((int)temp.x >= cub->parsing.map_x || (int)temp.x < 0 \
			|| (int)temp.y >= cub->parsing.map_y || (int)temp.y < 0 \
			|| cub->parsing.world_map[(int)temp.y][(int)temp.x] == '1' \
			/*&& is_cardinal(cub->parsing.world_map[(int)temp.x][(int)temp.y]) == -1*/)
			return (0);
	}
	else if (key == LEFT)
	{
		temp.x = cub->parsing.px;
		temp.y = cub->parsing.py;
		temp.x += temp_dir_ray.y * MOVE_SPEED;
		temp.y -= temp_dir_ray.x * MOVE_SPEED;
		if ((int)temp.x >= cub->parsing.map_x || (int)temp.x < 0 \
			|| (int)temp.y >= cub->parsing.map_y || (int)temp.y < 0 \
			|| cub->parsing.world_map[(int)temp.y][(int)temp.x] == '1' \
			/*&& is_cardinal(cub->parsing.world_map[(int)temp.x][(int)temp.y]) == -1*/)
			return (0);
	}
	return (1);
}
