#include "cub3D.h"

int	init_matrix_z(t_vars *cub)
{
	int	i;

	cub->ray_c.matrix_z = malloc(sizeof(float *) * 3);
	if (!cub->ray_c.matrix_z)
		return (0);
	i = -1;
	while (++i < 3)
	{
		cub->ray_c.matrix_z[i] = malloc(sizeof(float) * 3);
		if (!cub->ray_c.matrix_z[i])
			return (0);
	}
	return (1);
}

void	init_matrix(t_vars *cub)
{
	cub->ray_c.matrix_z[0][0] = cos(cub->ray_c.rota);
	cub->ray_c.matrix_z[0][1] = -sin(cub->ray_c.rota);
	cub->ray_c.matrix_z[0][2] = 0;
	cub->ray_c.matrix_z[1][0] = sin(cub->ray_c.rota);
	cub->ray_c.matrix_z[1][1] = cos(cub->ray_c.rota);
	cub->ray_c.matrix_z[1][2] = 0;
	cub->ray_c.matrix_z[2][0] = 0;
	cub->ray_c.matrix_z[2][1] = 0;
	cub->ray_c.matrix_z[2][2] = 1;
}