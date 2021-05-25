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

inline unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
	if (( r / distance * 1.2) < 255)
	{
		//printf("%d\n", l);
		r /= distance * 1.2;
	}
	if ((g / distance * 1.2) < 255)
	{
		g /= distance * 1.2;
	}
	if ((b / distance * 1.2) < 255)
	{
		b /= distance * 1.2;
	}
	return (r << 16 | g << 8 | b);
}