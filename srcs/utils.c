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

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	normalisation_v(t_vector *v)
{
	double	norm;

	norm = 1 /sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x *= norm;
	v->y *= norm;
	v->z *= norm;
}