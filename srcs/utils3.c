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
