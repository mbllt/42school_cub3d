#include "cub3D.h"

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
		cub->ray_c.rota_z = M_PI;
		init_matrix_z(cub);
		*ray = rotation_z(cub, *ray);
	}
	if (cub->parsing.cardinal == 'E')
	{
		cub->ray_c.rota_z = M_PI * 0.5;
		init_matrix_z(cub);
		*ray = rotation_z(cub, *ray);
	}
	if (cub->parsing.cardinal == 'W')
	{
		cub->ray_c.rota_z = M_PI * 1.5;
		init_matrix_z(cub);
		*ray = rotation_z(cub, *ray);
	}
	cub->ray_c.rota_z = temp;
}
