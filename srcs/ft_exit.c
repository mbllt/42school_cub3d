#include "cub3D.h"

static void	free_stock_rays(t_vars *cub)
{
	int	i;

	i = -1;
	while (++i < cub->parsing.rx)
	{
		if (cub->ray_c.stock_rays[i])
			free(cub->ray_c.stock_rays[i]);
	}
	if (cub->ray_c.stock_rays)
		free(cub->ray_c.stock_rays);
}

static void	free_matrix(t_vars *cub)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (cub->ray_c.matrix_z[i])
			free(cub->ray_c.matrix_z[i]);
	}
	free(cub->ray_c.matrix_z);
	i = -1;
	while (++i < 3)
	{
		if (cub->ray_c.matrix_x[i])
			free(cub->ray_c.matrix_x[i]);
	}
	free(cub->ray_c.matrix_x);
}

static void	free_plans(t_vars *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (cub->ray_c.plans[i])
			free(cub->ray_c.plans[i]);
		i++;
	}
	if (cub->ray_c.plans)
		free(cub->ray_c.plans);
}

static void	free_path(t_vars *cub)
{
	if (cub->parsing.no)
		free(cub->parsing.no);
	if (cub->parsing.no)
		free(cub->parsing.so);
	if (cub->parsing.no)
		free(cub->parsing.we);
	if (cub->parsing.no)
		free(cub->parsing.ea);
	if (cub->parsing.no)
		free(cub->parsing.f);
	if (cub->parsing.no)
		free(cub->parsing.c);
	if (cub->parsing.no)
		free(cub->parsing.s);
}

int	ft_exit(t_vars *cub)
{
	int	i;

	i = -1;
	mlx_destroy_window(cub->ray_c.mlx, cub->ray_c.win);
	free_stock_rays(cub);
	free_matrix(cub);
	free_plans(cub);
	if (cub->ray_c.sprite)
		free(cub->ray_c.sprite);
	ft_double_free(cub->parsing.file, cub->parsing.file_y -1);
	free_path(cub);
	ft_double_free(cub->parsing.world_map, cub->parsing.map_y);
	exit(0);
	return (1);
}