#include "cub3D.h"

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}t_dir;

static int	fill_in_plans(t_plan **plans, int cardinal, int size)
{
	int	i;
	// int	j;

	plans[cardinal] = malloc(sizeof(t_plan) * size + 1);
	if (!plans[cardinal])
		return (0);
	i = 0;
	while (i < size)
	{
		if (cardinal == SOUTH)
			plans[cardinal][i] = (t_plan){0, 1, 0, -i};
		else if (cardinal == EAST)
			plans[cardinal][i] = (t_plan){1, 0, 0, -i};
		i++;
	}
	i = size - 1;
	// j = 0;
	while (i >= 0)
	{
		if (cardinal == NORTH)
		{
			//printf("%d\n", j);
			plans[cardinal][i] = (t_plan){0, 1, 0, -i};
		}
		else if (cardinal == WEST)
			plans[cardinal][i] = (t_plan){1, 0, 0, -i};
		// j++;
		i--;
	}
	return (1);
}

int	init_plans(t_vars *cub)
{
	if (!(fill_in_plans(cub->ray_c.plans, NORTH, cub->parsing.map_y)))
		return (0);
	if (!(fill_in_plans(cub->ray_c.plans, SOUTH, cub->parsing.map_y)))
		return (0);
	if (!(fill_in_plans(cub->ray_c.plans, EAST, cub->parsing.map_x)))
		return (0);
	if (!(fill_in_plans(cub->ray_c.plans, WEST, cub->parsing.map_x)))
		return (0);
	// for (int i = 0;i < 2;i++)
	// {
	// 	for (int j = 0;j < cub->parsing.map_y;j++)
	// 		printf("%f\n", cub->ray_c.plans[i][j].d);
	// 	printf("\n");
	// }
	// printf("\n");
	// for (int i = 2;i < 4;i++)
	// {
	// 	for (int j = 0;j < cub->parsing.map_x;j++)
	// 		printf("%f\n", cub->ray_c.plans[i][j].d);
	// 	printf("\n");
	// }
	cub->ray_c.plans[4][0] = (t_plan){0, 0, 1, 0};
	cub->ray_c.plans[5][0] = (t_plan){0, 0, 1, -1};
	return (1);
	// cub->parsing.px = 0;
	// cub->parsing.py = 0;
	// cub->parsing.pz = 0.5;
	// cub->ray_c.plans[0] = (t_plan){0, 1, 0, 3};
	// cub->ray_c.plans[1] = (t_plan){0, 1, 0, -2};
	// cub->ray_c.plans[2] = (t_plan){1, 0, 0, -2};
	// cub->ray_c.plans[3] = (t_plan){1, 0, 0, 2};
	// cub->ray_c.plans[4] = (t_plan){0, 0, 1, 0};
	// cub->ray_c.plans[5] = (t_plan){0, 0, 1, -1};
	return (1);
}