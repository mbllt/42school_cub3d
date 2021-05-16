#include "cub3D.h"

void	intersct_dot(t_vars *cub, t_vector ray)
{
	cub->ray_c.xyz.x = cub->parsing.px + (ray.x * cub->ray_c.distance);
	cub->ray_c.xyz.y = cub->parsing.py + (ray.y * cub->ray_c.distance);
	cub->ray_c.xyz.z = cub->parsing.pz + (ray.z * cub->ray_c.distance);
}

static t_dot_intersct	compare_distance(t_dot_intersct *dot)
{
	t_dot_intersct	temp;
	int	i;

	temp.intersct = (t_vector){0, 0, 0};
	temp.t_distance = -1;
	temp.cardinal = -1;
	i = -1;
	while (++i < 6)
	{
		//printf("%f\n", dot[4].t_distance);
		if (dot[i].t_distance >= 0 && (temp.t_distance == -1 || dot[i].t_distance < temp.t_distance))
		{
			temp = dot[i];
		}
	}
	return (temp);
}

static void	init_dot(t_dot_intersct dot[])
{
	int i;

	i = 0;
	while (i < 6)
	{
		dot[i].intersct = (t_vector){0, 0, 0};
		dot[i].t_distance = -1;
		dot[i].cardinal = -1;
		i++;
	}
}

static void	check_direction(t_vars *cub, t_dot_intersct dot[], t_vector ray)
{
	if (ray.y < 0)
	{
		dot[0] = check_wall_n(cub, ray);
	}
	if (ray.y > 0)
	{
		dot[1] = check_wall_s(cub, ray);
	}
	if (ray.x > 0)
	{
		dot[2] = check_wall_e(cub, ray);
	}
	if (ray.x < 0)
	{
		dot[3] = check_wall_w(cub, ray);
	}
	dot[4] = check_wall_f(cub, ray);
	dot[5] = check_wall_c(cub, ray);
}

int	browse_rays(t_vars *cub, int width, int height)
{
	int				i;
	int				j;
	t_dot_intersct	dot[6];
	t_dot_intersct	prio_wall;
	t_vector		ray_temp;

	init_dot(dot);
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
		{
			ray_temp = cub->ray_c.stock_rays[i][j];
			ray_temp = rotation_x(cub, cub->ray_c.stock_rays[i][j]);
			ray_temp = rotation_z(cub, ray_temp);
			check_direction(cub, dot, ray_temp);
			prio_wall = compare_distance(dot);
			//if
			display(cub, i, j, prio_wall.cardinal);
		}
	}
	return (1);
}