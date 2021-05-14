#include "cub3D.h"

// typedef enum e_dir
// {
// 	NORTH,
// 	SOUTH,
// 	EAST,
// 	WEST,
// }t_dir;

// static int	fill_in_plans(t_plan **plans, int cardinal, int size)
// {
// 	int	i;

// 	plans[cardinal] = malloc(sizeof(t_plan) * size + 1);
// 	if (!plans[cardinal])
// 		return (0);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (cardinal == NORTH || cardinal == SOUTH)
// 			plans[cardinal][i] = (t_plan){0, 1, 0, -i};
// 		else
// 			plans[cardinal][i] = (t_plan){1, 0, 0, -i};
// 		i++;
// 	}
// 	return (1);
// }

int	init_plans(t_vars *cub)
{
	// if (!(fill_in_plans(cub->ray_c.plans, NORTH, cub->parsing.map_y)))
	// 	return (0);
	// if (!(fill_in_plans(cub->ray_c.plans, SOUTH, cub->parsing.map_y)))
	// 	return (0);
	// if (!(fill_in_plans(cub->ray_c.plans, EAST, cub->parsing.map_x)))
	// 	return (0);
	// if (!(fill_in_plans(cub->ray_c.plans, WEST, cub->parsing.map_x)))
	// 	return (0);
	// return (1);
	cub->parsing.px = 0;
	cub->parsing.py = 0;
	cub->ray_c.plans[0] = (t_plan){0, 1, 0, 3};
	cub->ray_c.plans[1] = (t_plan){0, 1, 0, -2};
	cub->ray_c.plans[2] = (t_plan){1, 0, 0, -2};
	cub->ray_c.plans[3] = (t_plan){1, 0, 0, 2};
	return (1);
}