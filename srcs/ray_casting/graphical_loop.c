#include "cub3D.h"

void	intersct_dot(t_vars *cub, t_vector ray, t_dot_intersct *intersct)
{
	(*intersct).dot.x = cub->parsing.px + (ray.x * (*intersct).t_distance);
	(*intersct).dot.y = cub->parsing.py + (ray.y * (*intersct).t_distance);
	(*intersct).dot.z = cub->parsing.pz + (ray.z * (*intersct).t_distance);
}

static t_dot_intersct	compare_distance(t_dot_intersct *intersct)
{
	t_dot_intersct	temp;
	int	i;

	temp.dot = (t_vector){0, 0, 0};
	temp.t_distance = -1;
	temp.cardinal = 5;
	i = -1;
	while (++i < 6)
	{
		if (intersct[i].t_distance >= 0 && intersct[i].cardinal != -1  && (temp.t_distance == -1 || intersct[i].t_distance < temp.t_distance))
		{
			temp = intersct[i];
		}
	}
	return (temp);
}

static void	init_intersct(t_dot_intersct intersct[])
{
	int i;

	i = 0;
	while (i < 6)
	{
		intersct[i].dot = (t_vector){0, 0, 0};
		intersct[i].t_distance = -1;
		intersct[i].cardinal = -1;
		i++;
	}
}

static void	check_direction(t_vars *cub, t_dot_intersct intersct[], t_vector ray)
{
	if (ray.y < 0)
	{	
		intersct[0] = check_wall_n(cub, ray, &intersct[0]);
	}
	if (ray.y > 0)
	{
		intersct[1] = check_wall_s(cub, ray, &intersct[1]);
	}
	if (ray.x > 0)
	{
		intersct[2] = check_wall_e(cub, ray, &intersct[2]);
	}
	if (ray.x < 0)
	{
		intersct[3] = check_wall_w(cub, ray, &intersct[3]);
	}
	intersct[4] = check_wall_f(cub, ray, &intersct[4]);
	intersct[5] = check_wall_c(cub, ray, &intersct[5]);
	intersct[6] = sprite(cub, ray, &intersct[6]);
}

void	*graphical_loop(void *thread_data)
{
	int				i;
	int				j;
	t_dot_intersct	intersct[7];
	t_dot_intersct	prio;
	t_vector		ray_temp;

	init_intersct(intersct);
	i = ((t_thread*)thread_data)->thread_num * \
			ceil((((t_thread*)thread_data)->cub.parsing.rx * 0.25));
	while (i < (((t_thread*)thread_data)->thread_num + 1) * \
			ceil((((t_thread*)thread_data)->cub.parsing.rx * 0.25)) \
			&& i < ((t_thread*)thread_data)->cub.parsing.rx)
	{
		j = 0;
		while (j < ((t_thread*)thread_data)->cub.parsing.ry)
		{
			ray_temp = ((t_thread*)thread_data)->cub.ray_c.stock_rays[i][j];
			ray_temp = rotation_x(&((t_thread*)thread_data)->cub, ray_temp);
			ray_temp = rotation_z(&((t_thread*)thread_data)->cub, ray_temp);
			check_direction(&((t_thread*)thread_data)->cub, intersct, ray_temp);
			prio = compare_distance(intersct);
			display(&((t_thread*)thread_data)->cub, i, j, prio);
			j++;
		}
		i++;
	}
	return ((void *)0);
}
