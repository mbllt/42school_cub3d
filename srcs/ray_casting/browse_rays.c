#include "cub3D.h"

static t_dot_intersct	compare_distance(t_dot_intersct *dot)
{
	t_dot_intersct	temp;
	int	i;

	temp.intersct = (t_vector){0, 0, 0};
	temp.t_distance = INT_MAX;
	temp.cardinal = -1;
	i = -1;
	while (++i < 6)
	{
		if (dot[i].t_distance >= 0 && dot[i].t_distance < temp.t_distance)
		{
			temp = dot[i];
		}
	}
	return (temp);
}

static void	init_dot(t_dot_intersct dot[])
{
	dot[0].intersct = (t_vector){0, 0, 0};
	dot[0].t_distance = -1;
	dot[0].cardinal = -1;
	dot[1].intersct = (t_vector){0, 0, 0};
	dot[1].t_distance = -1;
	dot[1].cardinal = -1;
	dot[2].intersct = (t_vector){0, 0, 0};
	dot[2].t_distance = -1;
	dot[2].cardinal = -1;
	dot[3].intersct = (t_vector){0, 0, 0};
	dot[3].t_distance = -1;
	dot[3].cardinal = -1;
	dot[4].intersct = (t_vector){0, 0, 0};
	dot[4].t_distance = -1;
	dot[4].cardinal = -1;
	dot[5].intersct = (t_vector){0, 0, 0};
	dot[5].t_distance = -1;
	dot[5].cardinal = -1;
}

static void	check_direction(t_vars *cub, t_dot_intersct dot[], int i, int j)
{
	if (cub->ray_c.stock_rays[i][j].y < 0)
	{
		dot[0] = check_wall_n(cub, cub->ray_c.stock_rays[i][j]);
	}
	if (cub->ray_c.stock_rays[i][j].y > 0)
	{
		dot[1] = check_wall_s(cub, cub->ray_c.stock_rays[i][j]);
	}
	if (cub->ray_c.stock_rays[i][j].x > 0)
	{
		dot[2] = check_wall_e(cub, cub->ray_c.stock_rays[i][j]);
		//printf("%d\n", dot[3].cardinal);
	}
	if (cub->ray_c.stock_rays[i][j].x < 0)
	{
		dot[3] = check_wall_w(cub, cub->ray_c.stock_rays[i][j]);
	}
	dot[4] = check_wall_f(cub, cub->ray_c.stock_rays[i][j]);
	dot[5] = check_wall_c(cub, cub->ray_c.stock_rays[i][j]);
}


static void	pixel_put(t_vars *cub, int i, int j, t_dot_intersct prio_wall)
{
	//printf("%f\n", prio_wall.intersct.z);
	// if (prio_wall.intersct.z < 1 && prio_wall.intersct.z >= 0)
	// {
		//printf("yoy\n");
		display(cub, i, j, prio_wall.cardinal);
	// }
	// else
	// {
	// 	if (prio_wall.intersct.z >= 1)
	// 		my_mlx_pixel_put(cub, i, j, BLUE);
	// 	if (prio_wall.intersct.z < 0)
	// 	{
	// 		my_mlx_pixel_put(cub, i, j, GREEN);
	// 	}
	// }
}

int	browse_rays(t_vars *cub, int width, int height)
{
	int				i;
	int				j;
	t_dot_intersct	dot[6];
	t_dot_intersct	prio_wall;

	init_dot(dot);
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
		{
			if (cub->ray_c.rota != 1.5 && cub->ray_c.rota != 0)
				rotation(cub, &cub->ray_c.stock_rays[i][j]);
			// if (cub->ray_c.rota != 0)
			// 	rotation(cub, &cub->ray_c.stock_rays[i][j]);
			my_mlx_pixel_put(cub, i, j, GREY);
			check_direction(cub, dot, i, j);
			prio_wall = compare_distance(dot);
			pixel_put(cub, i, j, prio_wall);
		}
	}
	return (1);
}