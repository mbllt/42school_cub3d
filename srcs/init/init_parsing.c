#include "cub3D.h"

static void	init_parsing2(t_vars *cub)
{
	cub->parsing.map_y = 0;
	cub->parsing.px = 0;
	cub->parsing.py = 0;
	cub->parsing.pz = 0.5;
	cub->parsing.cardinal = 0;
	cub->parsing.ff = 0;
	cub->parsing.cc = 0;
	cub->parsing.f_color_on = -1;
	cub->parsing.c_color_on = -1;
	cub->ray_c.nbr_sprite = 0;
	cub->ray_c.free_matrixxon = 0;
	cub->ray_c.free_matrixzon = 0;
	cub->ray_c.free_plans = 0;
	cub->ray_c.free_stock_rays = 0;
	cub->exit_good = 0;
}

void	init_parsing(t_vars *cub)
{
	cub->parsing.rx = 0;
	cub->parsing.ry = 0;
	cub->parsing.old_rx = 0;
	cub->parsing.old_ry = 0;
	cub->parsing.scale_on = 0;
	cub->parsing.no = NULL;
	cub->parsing.so = NULL;
	cub->parsing.ea = NULL;
	cub->parsing.we = NULL;
	cub->parsing.s = NULL;
	cub->parsing.f = NULL;
	cub->parsing.c = NULL;
	cub->parsing.nbr_param = 0;
	cub->parsing.map_x = 0;
	cub->parsing.zero = 0;
	init_parsing2(cub);
	cub->temp = -1;
	cub->i = 0;
	cub->fps = NULL;
}
