#include "cub3D.h"

int	malloc_matrix_x(t_vars *cub)
{
	int	i;

	cub->ray_c.matrix_x = malloc(sizeof(float *) * 3);
	if (!cub->ray_c.matrix_x)
		return (0);
	i = -1;
	while (++i < 3)
	{
		cub->ray_c.matrix_x[i] = malloc(sizeof(float) * 3);
		if (!cub->ray_c.matrix_x[i])
			return (0);
	}
	return (1);
}

int	init_matrix_x(t_vars *cub)
{
	cub->ray_c.matrix_x[0][0] = 1;
	cub->ray_c.matrix_x[0][1] = 0;
	cub->ray_c.matrix_x[0][2] = 0;
	cub->ray_c.matrix_x[1][0] = 0;
	cub->ray_c.matrix_x[1][1] = cos(cub->ray_c.rota_x);
	cub->ray_c.matrix_x[1][2] = -sin(cub->ray_c.rota_x);
	cub->ray_c.matrix_x[2][0] = 0;
	cub->ray_c.matrix_x[2][1] = sin(cub->ray_c.rota_x);
	cub->ray_c.matrix_x[2][2] = cos(cub->ray_c.rota_x);
	return (1);
}

int	malloc_matrix_z(t_vars *cub)
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

int	init_matrix_z(t_vars *cub)
{
	cub->ray_c.matrix_z[0][0] = cos(cub->ray_c.rota_z);
	cub->ray_c.matrix_z[0][1] = -sin(cub->ray_c.rota_z);
	cub->ray_c.matrix_z[0][2] = 0;
	cub->ray_c.matrix_z[1][0] = sin(cub->ray_c.rota_z);
	cub->ray_c.matrix_z[1][1] = cos(cub->ray_c.rota_z);
	cub->ray_c.matrix_z[1][2] = 0;
	cub->ray_c.matrix_z[2][0] = 0;
	cub->ray_c.matrix_z[2][1] = 0;
	cub->ray_c.matrix_z[2][2] = 1;
	return (1);
}
