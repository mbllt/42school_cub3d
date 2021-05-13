#include "cub3D.h"

t_dot_intersct	check_wall_N(t_vars *cub, t_vector ray)
{
	t_dot_intersct dot;
	int	i;

	dot.intersct = (t_vector){0, 0, 0};
	dot.t_distance = -1;
	dot.cardinal = -1;
	i = (int)cub->parsing.py;
	while(i >= 0)
	{
		if (cub->ray_c.plans_n[i].d == 5)
			i--;
		if ((intersct_plan(cub, cub->ray_c.plans_n[i], ray)) == 1 \
			&& (int)cub->ray_c.xyz.x >= 0 && (int)cub->ray_c.xyz.x <= cub->parsing.map_x \
			&& ((int)cub->ray_c.xyz.y - 1) >= 0 && ((int)cub->ray_c.xyz.y - 1) <= cub->parsing.map_y)
		{
			//printf("%f\n", cub->ray_c.plans_n[i].d);
			//printf("%f\n", cub->ray_c.xyz.z);
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0 \
				&& cub->parsing.world_map[(int)cub->ray_c.xyz.x][(int)cub->ray_c.xyz.y])
			{
				//printf("%c\n", cub->parsing.world_map[(int)cub->ray_c.xyz.x][(int)cub->ray_c.xyz.y - 1]);
				if (/*dot.cardinal == 0 && */cub->parsing.world_map[(int)cub->ray_c.xyz.x][(int)cub->ray_c.xyz.y - 1] == '1')
				{
					//printf("yoy\n");
					return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 0});
				}
				else
				dot = (t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1};
			}
			else
				dot = (t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1};
		}
		i--;
	}
	//printf("%d\n", dot.cardinal);
	//exit(0);
	return (dot);
}

t_dot_intersct	check_wall_S(t_vars *cub, t_vector ray)
{
	t_dot_intersct dot;
	int	i;

	dot.intersct = (t_vector){0, 0, 0};
	dot.t_distance = -1;
	dot.cardinal = -1;
	i = (int)cub->parsing.py;
	while (i < cub->parsing.map_x)
	{
		if (cub->ray_c.plans_s[i].d == 5)
			i++;
		if ((intersct_plan(cub, cub->ray_c.plans_s[i], ray)) == 1 \
			&& (int)cub->ray_c.xyz.x >= 0 && (int)cub->ray_c.xyz.x <= cub->parsing.map_x \
			&& (int)cub->ray_c.xyz.y - 1 >= 0 && (int)cub->ray_c.xyz.y - 1 <= cub->parsing.map_y)
		{
			//printf("%f\n", cub->ray_c.plans_n[i].d);
			//printf("%f\n", cub->ray_c.xyz.z);
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
			{
				//printf("%c\n", cub->parsing.world_map[(int)cub->ray_c.xyz.x][(int)cub->ray_c.xyz.y]);
				if (/*dot.cardinal == 1 && */cub->parsing.world_map[(int)cub->ray_c.xyz.x][(int)cub->ray_c.xyz.y] == '1')
					return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 1});
				else
				dot = (t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1};
			}
			else
				dot = (t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1};
		}
		i++;
	}
	return (dot);
}

t_dot_intersct	check_wall_E(t_vars *cub, t_vector ray)
{
	t_dot_intersct dot;
	int	i;

	dot.intersct = (t_vector){0, 0, 0};
	dot.t_distance = -1;
	dot.cardinal = -1;
	i = (int)cub->parsing.px;
	while (i < cub->parsing.map_y)
	{
		if (cub->ray_c.plans_e[i].d == 5)
			i++;
		if ((intersct_plan(cub, cub->ray_c.plans_e[i], ray)) == 1 \
			&& (int)cub->ray_c.xyz.x >= 0 && (int)cub->ray_c.xyz.x <= cub->parsing.map_x \
			&& (int)cub->ray_c.xyz.y >= 0 && (int)cub->ray_c.xyz.y <= cub->parsing.map_y)
		{
			//printf("%f\n", cub->ray_c.plans_n[i].d);
			//printf("%f\n", cub->ray_c.xyz.z);
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
			{
				//printf("%c\n", cub->parsing.world_map[(int)cub->ray_c.xyz.x][(int)cub->ray_c.xyz.y]);
				if (/*dot.cardinal == 2 && */cub->parsing.world_map[(int)cub->ray_c.xyz.x][(int)cub->ray_c.xyz.y] == '1')
					return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 2});
				else
					dot = (t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1};
			}
			else
				dot = (t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1};
		}
		i++;
	}
	return (dot);
}

t_dot_intersct	check_wall_W(t_vars *cub, t_vector ray)
{
	t_dot_intersct dot;
	int	i;
	dot.intersct = (t_vector){0, 0, 0};
	dot.t_distance = -1;
	dot.cardinal = -1;
	i = (int)cub->parsing.px;
	while (i >= 0)
	{
		if (cub->ray_c.plans_w[i].d == 5)
			i--;
		if ((intersct_plan(cub, cub->ray_c.plans_w[i], ray)) == 1 \
			&& ((int)cub->ray_c.xyz.x - 1) >= 0 && ((int)cub->ray_c.xyz.x - 1) <= cub->parsing.map_x \
			&& (int)cub->ray_c.xyz.y >= 0 && (int)cub->ray_c.xyz.y <= cub->parsing.map_y)
		{
			if (cub->ray_c.xyz.z < 1 && cub->ray_c.xyz.z >= 0)
			{
				if (/*dot.cardinal == 3 && */cub->parsing.world_map[(int)cub->ray_c.xyz.x - 1][(int)cub->ray_c.xyz.y] == '1')
					return ((t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, 3});
				else
					dot = (t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1};
			}
			else
				dot = (t_dot_intersct){cub->ray_c.xyz, cub->ray_c.distance, -1};
		}
		i--;
	}
	return (dot);
}