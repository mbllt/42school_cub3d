#include "cub3D.h"

static void	free_stock_rays_and_save_on(t_vars *cub)
{
	int	i;

	if (cub->ray_c.free_stock_rays == 1)
	{
		i = -1;
		while (++i < cub->parsing.rx)
		{
			if (cub->ray_c.stock_rays[i])
				free(cub->ray_c.stock_rays[i]);
		}
		if (cub->ray_c.stock_rays)
			free(cub->ray_c.stock_rays);
	}
	if (cub->save_on == 1)
	{
		i = -1;
		while (++i < cub->parsing.rx)
		{
			if (cub->pixel_data[i])
				free(cub->pixel_data[i]);
		}
		free(cub->pixel_data);
	}
}

static void	free_matrix(t_vars *cub)
{
	int	i;

	if (cub->ray_c.free_matrixzon == 1)
	{
		i = -1;
		while (++i < 3)
		{
			if (cub->ray_c.matrix_z[i])
				free(cub->ray_c.matrix_z[i]);
		}
		free(cub->ray_c.matrix_z);
	}
	if (cub->ray_c.free_matrixxon == 1)
	{
		i = -1;
		while (++i < 3)
		{
			if (cub->ray_c.matrix_x[i])
				free(cub->ray_c.matrix_x[i]);
		}
		free(cub->ray_c.matrix_x);
	}
}

static void	free_plans(t_vars *cub)
{
	int	i;

	if (cub->ray_c.free_plans == 1)
	{
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
}

static void	free_path(t_vars *cub)
{
	int	i;

	if (cub->parsing.no)
		free(cub->parsing.no);
	if (cub->parsing.so)
		free(cub->parsing.so);
	if (cub->parsing.we)
		free(cub->parsing.we);
	if (cub->parsing.ea)
		free(cub->parsing.ea);
	if (cub->parsing.f_color_on == 0)
		free(cub->parsing.f);
	if (cub->parsing.c_color_on == 0)
		free(cub->parsing.c);
	if (cub->parsing.s)
		free(cub->parsing.s);
	i = -1;
	if (cub->ray_c.free_text == 1)
		while (++i < 7)
			if (cub->parsing.textures[i].img)
				if (mlx_destroy_image(cub->ray_c.mlx, \
					cub->parsing.textures[i].img))
					write(1, "\nDestroy image did not work\n", 27);
}

int	ft_exit(t_vars *cub)
{
	free_stock_rays_and_save_on(cub);
	free_matrix(cub);
	free_plans(cub);
	free_path(cub);
	ft_double_free(cub->parsing.world_map, cub->parsing.map_y);
	if (cub->fps)
		free(cub->fps);
	if (cub->ray_c.sprite)
		free(cub->ray_c.sprite);
	if (cub->ray_c.free_win == 1)
		ft_destroy(cub);
	if (cub->exit_good == 1)
		exit(1);
	exit(0);
	return (1);
}
