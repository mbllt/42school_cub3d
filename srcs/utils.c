#include "cub3D.h"

inline float	norm_v(t_vector v)
{
	return ((sqrt(v.x * v.x + v.y * v.y + v.z * v.z)));
}

t_vector	normalisation_v(t_vector v)
{
	float	norm;

	norm = 1 / norm_v(v);
	v.x *= norm;
	v.y *= norm;
	v.z *= norm;
	return (v);
}

inline float	scalaire_v(t_vector v, t_vector v2)
{
	return ((v.x * v2.x) + (v.y * v2.y) + (v.z * v2.z));
}

int	get_index_x(void *thread_data)
{
	int	index;

	index = ((t_thread *)thread_data)->thread_num * \
			ceil((((t_thread *)thread_data)->cub.parsing.rx * 0.25));
	return (index);
}

void	init(t_vars *cub, t_dot_intersct *sprite, float *r_temp)
{
	int	i;

	i = 0;
	while (i < cub->ray_c.nbr_sprite)
	{
		r_temp[i] = -1;
		sprite[i].dot = (t_vector){0, 0, 0};
		sprite[i].t_distance = -1;
		sprite[i].cardinal = -1;
		i++;
	}
}
