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