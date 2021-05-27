#include "cub3D.h"

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
	cub->parsing.map_y = 0;
	cub->parsing.px = 0;
	cub->parsing.py = 0;
	cub->parsing.pz = 0.5;
	cub->parsing.cardinal = 0;
	cub->parsing.ff = 0;
	cub->parsing.cc = 0;
	cub->parsing.f_color_on = -1;
	cub->parsing.c_color_on = -1;
}
