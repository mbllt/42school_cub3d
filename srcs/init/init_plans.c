#include "cub3D.h"

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}t_dir;

static t_plan	*fill_in_plans(t_vars *cub, int size, int cardinal)
{
	t_plan	*str;

	if (cardinal == NORTH)
	{
		str = find_walls_n(cub, size, cardinal);
		printf("NORTH :%s\n", str);
	}
	if (cardinal == SOUTH)
	{
		str = find_walls_s(cub, size, cardinal);
		printf("SOUTH :%s\n", str);
	}
	if (cardinal == EAST)
	{
		str = find_walls_e(cub, size, cardinal);
		printf("EAST :%s\n", str);
	}
	if (cardinal == WEST)
	{
		str = find_walls_w(cub, size, cardinal);
		printf("WEST :%s\n", str);
	}

	return (str);
}

int	init_plans(t_vars *cub)
{
	cub->ray_c.plans_n = fill_in_plans(cub, cub->parsing.map_y + 1, NORTH);
	if (!cub->ray_c.plans_n)
		return (0);
	cub->ray_c.plans_s = fill_in_plans(cub, cub->parsing.map_y + 1, SOUTH);
	if (!cub->ray_c.plans_s)
		return (0);
		cub->ray_c.plans_e = fill_in_plans(cub, cub->parsing.map_x + 1, EAST);
	if (!cub->ray_c.plans_e)
		return (0);
		cub->ray_c.plans_w = fill_in_plans(cub, cub->parsing.map_x + 1, WEST);
	if (!cub->ray_c.plans_w)
		return (0);
	return (1);
}
	// int	i;
	// int	j;

	// i = cub->parsing.map_y - 1;
	// j = (-1) * cub->parsing.map_y;
	// while (i >= 0)
	// {
	// 	cub->ray_c.plans_v[i] = (t_plan){1, 0, 0, j};
	// 	j++;
	// 	i--;
	// }
	// i = cub->parsing.map_x - 1;
	// j = (-1) * cub->parsing.map_x;
	// while (i >= 0)
	// {
	// 	cub->ray_c.plans_h[i] = (t_plan){0, 1, 0, j};
	// 	j++;
	// 	i--;
	// }

	// cub->ray_c.plans_h[0] = (t_plan){0, 1, 0, 3};
	// cub->ray_c.plans_h[1] = (t_plan){0, 1, 0, -2};
	// cub->ray_c.plans_v[0] = (t_plan){1, 0, 0, 2};
	// cub->ray_c.plans_v[1] = (t_plan){1, 0, 0, -1};

	// cub->ray_c.plans_w[0] = (t_plan){0, 1, 0, 3};		NORD
	// cub->ray_c.plans_w[1] = (t_plan){0, 1, 0, -2};		SUD
	// cub->ray_c.plans_h[0] = (t_plan){1, 0, 0, 2};		WEST
	// cub->ray_c.plans_h[1] = (t_plan){1, 0, 0, -2};		EAST