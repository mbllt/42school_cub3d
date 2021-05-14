#include "cub3D.h"

static t_dot_intersct	compare_distance(t_dot_intersct *dot)
{
	t_dot_intersct	temp;
	t_dot_intersct	temp_bis;
	int	i;

	temp.intersct = (t_vector){0, 0, 0};
	temp.t_distance = -1;
	temp.cardinal = -1;
	i = -1;
	while (++i < 4)
	{
		//printf("%d : %f\n", i, dot[i].t_distance);
		if (dot[i].t_distance >= 0 && temp.cardinal == -1)
		{
			//printf("%d\n", dot[i].cardinal);
			temp = dot[i];
			//printf("%d\n", temp.cardinal);
			// temp.intersct = dot[i].intersct;
			// temp.t_distance = dot[i].t_distance;
			// temp.cardinal = dot[i].cardinal;
		}
		if (dot[i].t_distance >= 0 && dot[i].t_distance < temp.t_distance)
		{
			//printf("oyo\n");
			temp_bis = dot[i];
			return (temp_bis);
		}
	}
	//printf("%d\n", temp.cardinal);
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
}


static void	pixel_put(t_vars *cub, int i, int j, t_dot_intersct prio_wall)
{
	//printf("%f\n", prio_wall.intersct.z);
	if (prio_wall.intersct.z < 1 && prio_wall.intersct.z >= 0)
	{
		//printf("yoy\n");
		display(cub, i, j, prio_wall.cardinal);
	}
	else
	{
		if (prio_wall.intersct.z >= 1)
			my_mlx_pixel_put(cub, i, j, BLUE);
		if (prio_wall.intersct.z < 0)
			my_mlx_pixel_put(cub, i, j, GREEN);
	}
}

int	browse_rays(t_vars *cub, int width, int height)
{
	int				i;
	int				j;
	t_dot_intersct	dot[4];
	t_dot_intersct	prio_wall;

	init_dot(dot);
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
		{
			if (cub->ray_c.rota != 0)
				rotation(cub, &cub->ray_c.stock_rays[i][j]);
			my_mlx_pixel_put(cub, i, j, BLACK);
			check_direction(cub, dot, i, j);
			prio_wall = compare_distance(dot);
			pixel_put(cub, i, j, prio_wall);
		}
	}
	return (1);
}