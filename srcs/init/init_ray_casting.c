#include "cub3D.h"

static int	init_malloc_plans(t_vars *cub)
{
	cub->ray_c.plans = malloc(sizeof(t_plan) * 4);
	if (!cub->ray_c.plans)
		return (0);
	return(1);
}

static void	init_key(t_vars *cub)
{
	cub->ray_c.key.right = 0;
	cub->ray_c.key.left = 0;
	cub->ray_c.key.down = 0;
	cub->ray_c.key.up = 0;
	cub->ray_c.key.rot_right = 0;
	cub->ray_c.key.rot_left = 0;
	cub->ray_c.key.exit = 0;
}

static void	init_xyz(t_vars *cub)
{
	cub->ray_c.xyz.x = 0;
	cub->ray_c.xyz.y = 0;
	cub->ray_c.xyz.z = 0;
}

int	init_ray_casting(t_vars *cub)
{
	cub->ray_c.fov = 0;
	cub->ray_c.ratio_horizon = 0;
	cub->ray_c.ratio_vertical = 0;
	cub->ray_c.mlx = NULL;
	cub->ray_c.win = NULL;
	cub->ray_c.img = 0;
	cub->ray_c.addr = 0;
	cub->ray_c.bits_per_pixel = 0;
	cub->ray_c.line_length = 0;
	cub->ray_c.endian = 0;
	cub->ray_c.distance = 0;
	cub->ray_c.rota = 0;
	init_key(cub);
	init_vars_rays(cub);
	if (!(init_stock_rays(cub, cub->parsing.rx, cub->parsing.ry)))
		return (0);
	init_xyz(cub);
	if (!(init_malloc_plans(cub)))
		return (0);
	if (!(init_matrix_z(cub)))
		return (0);
	init_matrix(cub);
	return (1);
}