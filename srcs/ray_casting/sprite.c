#include "cub3D.h"

static void	init(t_vars *cub, t_sprite **sprite)
{
	int	i;

	i = 0;
	while (i < cub->ray_c.nbr_sprite)
	{
		(*sprite)[i].dot = (t_vector){0,0,0};
		(*sprite)[i].distance = 0;
		(*sprite)[i].ray = (t_vector){0,0,0};
		i++;
	}
}

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
	// if ((*intersct).dot.z < 1 && (*intersct).dot.z >= 0)
	// 	printf("%fx+%fy+%fz+%f=0 | (%f,%f,%f) | %f\n", plan.a, plan.b, plan.c, plan.d, intersct->dot.x, intersct->dot.y, intersct->dot.z, intersct->t_distance);
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
	// if (intersct->dot.z >= 0 && intersct->dot.z < 1 && r < 1 && r >= 0)
	// 	printf("%f\n", r);
	return (r);
}

t_dot_intersct	compare_sprite(t_vars *cub, t_sprite *sprite)
{
	t_dot_intersct	temp;
	int	i;

	temp.dot = (t_vector){0, 0, 0};
	temp.t_distance = -1;
	temp.cardinal = -1;
	i = 0;
	while (i < cub->ray_c.nbr_sprite)
	{
		//printf("%d\n", i);
		if (sprite[i].distance > 0 && (temp.t_distance == -1 \
			|| sprite[i].distance < temp.t_distance))
		{
			//printf("%d, %f\n", i, sprite[i].distance);
			temp.t_distance = sprite[i].distance;
			temp.dot.x = sprite[i].dot.x;
			temp.dot.y = sprite[i].dot.y;
			temp.dot.z = sprite[i].dot.z;
		}
		i++;
	}
	temp.cardinal = 6;
	//printf("%f\n", temp.t_distance);
	return (temp);
}

t_dot_intersct	sprite(t_vars *cub, t_vector ray, t_dot_intersct *intersct, \
						float *r)
{
	int				i;
	t_dot_intersct	temp;

	init(cub, &cub->ray_c.sprite);
	i = 0;
	while (i < cub->ray_c.nbr_sprite)
	{
		if (cub->ray_c.sprite[i].sprite_front >= 0 && intersct_sprite \
			(cub, ray, cub->ray_c.sprite[i].plans, intersct) == 1)
		{
			*r = get_r(cub, intersct, i);
			if ((*intersct).dot.z < 1 && (*intersct).dot.z >= 0 \
				&& *r >= 0 && *r < 1)
			{
				cub->ray_c.sprite[i].dot.x = (*intersct).dot.x;
				cub->ray_c.sprite[i].dot.y = (*intersct).dot.y;
				cub->ray_c.sprite[i].dot.z = (*intersct).dot.z;
				cub->ray_c.sprite[i].distance = (*intersct).t_distance;
				cub->ray_c.sprite[i].ray = (*intersct).ray;
				//printf("%i, %f\n", i, cub->ray_c.sprite[i].distance);

			}
			// else if ((*intersct).dot.z >= 1 || (*intersct).dot.z < 0)
			// {
			// 	intersct->cardinal = -1;
			// 	break;
			// }
		}
		i++;
	}
	temp = compare_sprite(cub, cub->ray_c.sprite);
	//printf("%f\n", temp.t_distance);
	return (temp);
}