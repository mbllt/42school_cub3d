#include "cub3D.h"

void	ft_double_free(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
	str = NULL;
}

inline unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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
