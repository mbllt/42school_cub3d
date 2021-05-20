#include "cub3D.h"

static int	intersct_sprite(t_vars *cub, t_vector ray, t_plan plan, \
							t_dot_intersct *intersct)
{
	float		division;

	division = (plan.a * ray.x) + (plan.b * ray.y);
	if (division == 0)
		return (0);
	(*intersct).t_distance = - ((plan.a * cub->parsing.px) \
							+ (plan.b * cub->parsing.py) + plan.d);
	(*intersct).t_distance /= division;
	if ((*intersct).t_distance < 0)
		return (0);
	intersct_dot(cub, ray, intersct);
	//if (i != 0)
		// printf("%d\n", i);
	//printf("%fx+%fy+%fz+%f=0 | ", plan.a, plan.b, plan.c, plan.d);
	//printf("(%f,%f,%f)\n", intersct->dot.x, intersct->dot.y, intersct->dot.z);
	return (1);
}

static int	get_r(t_vars *cub, t_dot_intersct *intersct, float *r, t_vector v)
{
	t_vector	u;
	t_vector	v2;

	u = (t_vector){
		.x = intersct->dot.x - cub->ray_c.sprite_p->x,
		.y = intersct->dot.y - cub->ray_c.sprite_p->y,
		.z = 0
	};
	v2 = (t_vector){
		.x = v.y,
		.y = - v.x,
		.z  = 0
	};
	v2 = normalisation_v(v2);
	*r = u.x * v2.x + u.y * v2.y + 0.5;
	return (1);
}

// static int	is_sprite(t_vars *cub, t_dot_intersct *intersct)
// {
// 	int	x;
// 	int	y;

// 	x = (int)intersct->dot.x;
// 	y = (int)intersct->dot.y;
// 	if (x >= 0 && x < cub->parsing.map_x \
// 		&& y >= 0 && y < cub->parsing.map_y \
// 		&& cub->parsing.world_map[y][x] == '2')
// 	{
// 		return (1);
// 	}
// 	return (0);
// }

int	sprite(t_vars *cub, t_vector ray, t_dot_intersct *intersct, float *r)
{
	int	i;

	i = 0;
	//printf("%f\n", cub->ray_c.plans_sprite[0].d);
	while (i < cub->ray_c.nbr_sprite)
	{
		//printf("%d\n", i);
		if ((intersct_sprite(cub, ray, cub->ray_c.plans_sprite[i], intersct)) \
			== 1 && get_r(cub, intersct, r, cub->ray_c.v) == 1)
		{
			// if (r >= 0 && r < 1)
			// 	printf("%d, %f\n", i, r);
			if ((*intersct).dot.z < 1 && (*intersct).dot.z >= 0 \
					&& *r >= 0 && *r < 1)
			{
				intersct->cardinal = 6;
				break;
			}
			else if ((*intersct).dot.z >= 1 || (*intersct).dot.z < 0)
			{
				intersct->cardinal = -1;
				break;
			}
		}
		//printf("%d\n", i);
		i++;
	}
	return (1);
}