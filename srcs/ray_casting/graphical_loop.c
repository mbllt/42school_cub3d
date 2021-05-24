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
	int				i;

	temp.dot = (t_vector){0, 0, 0};
	temp.t_distance = -1;
	temp.cardinal = 6;
	i = -1;
	while (++i < 7)
	{
		if (intersct[i].cardinal != -1)
		{
			if (intersct[i].t_distance >= 0 && (temp.t_distance == -1 \
				|| intersct[i].t_distance < temp.t_distance))
			{
				temp = intersct[i];
			}
		}
	}
	return (temp);
}

static void	init_intersct(t_dot_intersct intersct[])
{
	int	i;

	i = 0;
	while (i < 7)
	{
		intersct[i].dot = (t_vector){0, 0, 0};
		intersct[i].t_distance = -1;
		intersct[i].cardinal = -1;
		i++;
	}
}

static int	dir(t_vars *cub, t_dot_intersct intersct[], \
			t_vector ray, float *r)
{
	init_intersct(intersct);
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
	*r = 0;
	intersct[6] = sprite(cub, ray, &intersct[6], r);
	if (intersct[6].cardinal == -10)
		return (0);
	return (1);
}

void	*graphical_loop(void *thread_data)
{
	t_index			index;
	t_dot_intersct	intersct[7];
	t_dot_intersct	prio;
	t_vector		ray_temp;
	float			r;

	index.x = get_index_x(thread_data);
	while (index.x < (((t_thread *)thread_data)->thread_num + 1) *\
			ceil((((t_thread *)thread_data)->cub.parsing.rx * 0.25)) \
			&& index.x < ((t_thread *)thread_data)->cub.parsing.rx)
	{
		index.y = 0;
		while (index.y < ((t_thread *)thread_data)->cub.parsing.ry)
		{
			ray_temp = get_ray_temp(thread_data, index.x, index.y);
			if (!(dir(&((t_thread *)thread_data)->cub, intersct, ray_temp, &r)))
				return ((void *) - 1);
			prio = compare_distance(intersct);
			prio.ray = ray_temp;
			display(thread_data, index.x, index.y, prio, r);
			index.y++;
		}
		index.x++;
	}
	return ((void *)0);
}
