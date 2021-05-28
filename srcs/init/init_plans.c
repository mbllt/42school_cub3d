#include "cub3D.h"

static int	fill_in_plans(t_vars *cub, t_plan **plans, int cardinal, int size)
{
	int	i;

	plans[cardinal] = malloc(sizeof(t_plan) * size);
	if (!plans[cardinal])
		return (0);
	i = -1;
	while (++i < size)
	{
		if (cardinal == SOUTH)
			plans[cardinal][i] = (t_plan){0, 1, 0, -i};
		else if (cardinal == EAST)
			plans[cardinal][i] = (t_plan){1, 0, 0, -i};
	}
	i = size - 1;
	while (i >= 0)
	{
		if (cardinal == NORTH)
		{
			plans[cardinal][i] = (t_plan){0, 1, 0, -i};
		}
		else if (cardinal == WEST)
			plans[cardinal][i] = (t_plan){1, 0, 0, -i};
		i--;
	}
	cub->ray_c.free_plans = 1;
	return (1);
}

int	init_plans(t_vars *cub)
{
	if (!(fill_in_plans(cub, cub->ray_c.plans, NORTH, cub->parsing.map_y + 1)))
		return (0);
	if (!(fill_in_plans(cub, cub->ray_c.plans, SOUTH, cub->parsing.map_y + 1)))
		return (0);
	if (!(fill_in_plans(cub, cub->ray_c.plans, EAST, cub->parsing.map_x + 1)))
		return (0);
	if (!(fill_in_plans(cub, cub->ray_c.plans, WEST, cub->parsing.map_x + 1)))
		return (0);
	cub->ray_c.plans[4][0] = (t_plan){0, 0, 1, 0};
	cub->ray_c.plans[5][0] = (t_plan){0, 0, 1, -1};
	return (1);
}
