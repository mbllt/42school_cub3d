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
	temp.cardinal = -1;
	i = -1;
	while (++i < 6)
	{
		//printf("%f\n", intersct[i].t_distance);
		if (intersct[i].t_distance >= 0 && (temp.t_distance == -1 || intersct[i].t_distance < temp.t_distance))
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
}

void	*graphical_loop(void *thread_data)
{
	int				i;
	int				j;
	t_dot_intersct	intersct[6];
	t_dot_intersct	prio_wall;
	t_vector		ray_temp;

	init_intersct(intersct);
	i = ((t_thread*)thread_data)->thread_num * \
			ceil((((t_thread*)thread_data)->cub.parsing.rx * 0.25));
	// int max = (((t_thread*)thread_data)->thread_num + 1) * \
	// 		ceil((((t_thread*)thread_data)->cub.parsing.rx * 0.25));
	// printf("%d\n", max);
	while (i < (((t_thread*)thread_data)->thread_num + 1) * \
			ceil((((t_thread*)thread_data)->cub.parsing.rx * 0.25)) \
			&& i < ((t_thread*)thread_data)->cub.parsing.rx)
	{
		j = 0;
		while (j < ((t_thread*)thread_data)->cub.parsing.ry)
		{
			// if (j == 0 && i > 150)
			// 	printf("%d\n", i);
			// if (j == 0)
			// 	printf("%d for thread :%d\n", i, (int)pthread_self());
			ray_temp = ((t_thread*)thread_data)->cub.ray_c.stock_rays[i][j];
			ray_temp = rotation_x(&((t_thread*)thread_data)->cub, ray_temp);
			ray_temp = rotation_z(&((t_thread*)thread_data)->cub, ray_temp);
			check_direction(&((t_thread*)thread_data)->cub, intersct, ray_temp);
			prio_wall = compare_distance(intersct);
			display(&((t_thread*)thread_data)->cub, i, j, prio_wall);
			j++;
		}
		i++;
	}
	return ((void *)0);
}

// int	graphical_loop(t_vars *cub, int width, int height)
// {
// 	int				i;
// 	int				j;
// 	t_dot_intersct	intersct[6];
// 	t_dot_intersct	prio_wall;
// 	t_vector		ray_temp;

// 	(void)width;
// 	(void)height;
// 	init_intersct(intersct);
// 	i = -1;
// 	while (++i < cub->parsing.rx)
// 	{
// 		j = -1;
// 		while (++j < cub->parsing.ry)
// 		{
// 			ray_temp = cub->ray_c.stock_rays[i][j];
// 			ray_temp = rotation_x(cub, cub->ray_c.stock_rays[i][j]);
// 			ray_temp = rotation_z(cub, ray_temp);
// 			check_direction(cub, intersct, ray_temp);
// 			prio_wall = compare_distance(intersct);
// 			display(cub, i, j, prio_wall);
// 		}
// 	}
// 	return (1);
// }