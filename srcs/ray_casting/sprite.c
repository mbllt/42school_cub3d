#include "cub3D.h"

static int	intersct_sprite(t_vars *cub, t_vector ray, t_plan plan, \
							t_dot_intersct *intersct, int x, int y)
{
	float		division;

	(void)x;
	(void)y;
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
	// if (y == 400 && x == 300)
	// {
	// 	printf("%fx+%fy+%fz+%f=0 | ", plan.a, plan.b, plan.c, plan.d);
	// 	printf("(%f,%f,%f)\n\n", intersct->dot.x, intersct->dot.y, intersct->dot.z);
	// }
	return (1);
}

static float	get_r(t_vars *cub, t_dot_intersct *intersct, int i)
{
	t_vector	u;
	float		r;

	u = (t_vector){
		.x = intersct->dot.x - cub->ray_c.sprite[i].pos.x,
		.y = intersct->dot.y - cub->ray_c.sprite[i].pos.y,
		.z = 0
	};
	r = scalaire_v(u, cub->ray_c.sprite[i].v2) + 0.5;
	// if (intersct->dot.z >= 0 && intersct->dot.y < 1 && (r >= 1 || r < 0))
	// 	printf("%f\n", r);
	return (r);
}

int	sprite(t_vars *cub, t_vector ray, t_dot_intersct *intersct, float *r, int y, int x)
{
	int	i;

	i = 0;

	while (i < cub->ray_c.nbr_sprite)
	{
		if ((intersct_sprite(cub, ray, cub->ray_c.sprite[i].plans, intersct, x, y)) \
			== 1 && get_r(cub, intersct, i))
		{
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
		i++;
	}
	return (1);
}